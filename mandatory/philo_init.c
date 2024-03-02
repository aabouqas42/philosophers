/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:01:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/02 22:36:13 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_pthread/_pthread_t.h>
#include <unistd.h>


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
	t_philo		*philo;
	pthread_t	_monitor;
	int		i;

	i = 0;
	while (i < data->n_philos)
	{
		philo = &data->philos[i];
		if (pthread_create(&philo->philo, NULL, _main, &data->philos[i]))
			return (_free(data), -1);
		i++;
	}
	pthread_create(&_monitor, NULL, monitor, data);
	pthread_join(_monitor, NULL);
	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->philos[i].philo, NULL);
		i++;
	}
	return (0);
}


int	data_init(t_data *data, int argc, char **argv)
{
	size_t	start_time;
	int		i;

	start_time = getime();
	data->someone_died = 0;
	i = 0;
	while (i < data->n_philos)
	{
		data->philos[i].number = i + 1;
		data->philos[i].start_time = start_time;
		data->philos[i].last_meal = start_time;
		data->philos[i].someone_died = &data->someone_died;
		data->philos[i].time_to_die = _atoi(argv[2]);
		data->philos[i].time_to_eat = _atoi(argv[3]);
		data->philos[i].time_to_sleep = _atoi(argv[4]);
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
