/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:01:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/29 21:48:06 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <sys/_types/_size_t.h>

void	forks_init(t_data *data)
{
	int	i;
	
	data->philos[0].left_fork = &data->forks[data->n_philos - 1];
	data->philos[0].right_fork = &data->forks[0];
	i = 1;
	while (i < data->n_philos)
	{
		data->philos[i].left_fork = &data->forks[i - 1];
		data->philos[i].right_fork = &data->forks[i];
		i++;
	}
}

int	create_threads(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&data->philos[i].philo,
			NULL, _main, &data->philos[i]))
			return (_free(data), -1);
		i++;
	}
	i = 0;
	_usleep(100);
	while (i < data->n_philos)
	{
		if (pthread_detach(data->philos[i].philo) == 1)
			return (_free(data), -1);
		i++;
	}
	return (0);
}

int	data_init(t_data *data, int argc, char **argv)
{
	size_t	start_time;
	int		i;

	start_time = getime();
	data->somone_died = 0;
	i = 0;
	while (i < data->n_philos)
	{
		data->philos[i].number = i + 1;
		data->philos[i].start_time = start_time;
		data->philos[i].last_meal = start_time;
		data->philos[i].time_to_die = _atoi(argv[2]);
		data->philos[i].time_to_eat = _atoi(argv[3]);
		data->philos[i].time_to_sleep = _atoi(argv[4]);
		data->philos[i].somone_died = &data->somone_died;
		if (argc == 6)
			data->philos[i].meal_count = _atoi(argv[5]);
		else
			data->philos[i].meal_count = -1;
		i++;
	}
	return (0);
}

int	print_state(t_philo *philo, char *state)
{
	size_t	time;

	pthread_mutex_lock(philo->printf);
	time = getime() - philo->start_time;
	printf("%zu %d %s\n", time, philo->number, state);
	pthread_mutex_unlock(philo->printf);
	return (0);
}
