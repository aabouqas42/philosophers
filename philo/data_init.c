/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:01:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/05 23:50:35 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	int			i;

	i = 0;
	while (i < data->n_philos)
	{
		philo = &data->philos[i];
		if (pthread_create(&philo->philo, NULL, _main, &data->philos[i]))
			return (_free(data), -1);
		if (pthread_detach(data->philos[i].philo))
			return (_free(data), -1);
		usleep(50);
		i++;
	}
	return (0);
}

int	data_init(t_data *data, int argc, char **argv)
{
	size_t	start_time;
	int		i;

	start_time = getime();
	i = 0;
	while (i < data->n_philos)
	{
		data->philos[i].number = i + 1;
		data->philos[i].start_time = start_time;
		data->philos[i].last_meal = start_time;
		data->philos[i].t_2_d = _atoi(argv[2]);
		data->philos[i].t_2_e = _atoi(argv[3]);
		data->philos[i].t_2_s = _atoi(argv[4]);
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
