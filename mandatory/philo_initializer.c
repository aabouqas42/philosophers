/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:31:01 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/23 15:25:41 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	init_data(t_data *data, char **argv)
{
	int	i;

	data->philosphers = _atoi(argv[1]);
	data->philosophers = malloc (sizeof(t_philos) * data->philosphers);
	if (data->philosophers == NULL)
		return (-1);
	i = 0;
	while (i < data->philosphers)
	{
		data->philosophers[i].time_to_die = _atoi(argv[2]);
		data->philosophers[i].time_to_eat = _atoi(argv[3]);
		data->philosophers[i].time_to_sleep = _atoi(argv[4]);
		data->philosophers[i].number = i + 1;
		data->philosophers[i].last_meal_time = 0;
		data->philosophers[i].start_time = getime();
		i++;
	}
	return (0);
}

void	init_threads(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc (sizeof(pthread_mutex_t) * data->philosphers);
	while (i < data->philosphers)
	{
		pthread_mutex_init(&data->forks[i++], NULL);
		pthread_mutex_init(&data->philosophers[i].lock_printf, NULL);
	}
	data->philosophers[0].left_fork = &data->forks[data->philosphers - 1];
	data->philosophers[0].right_fork = &data->forks[0];
	i = 1;
	while (i < data->philosphers)
	{
		data->philosophers[i].left_fork = &data->forks[i - 1];
		data->philosophers[i].right_fork = &data->forks[i];
		i++;
	}
	i = 0;
	while (i < data->philosphers)
	{
		pthread_create(&data->philosophers[i].philosopher, NULL, philo_start, &data->philosophers[i]);
		i++;
	}
	i = 0;
	while (i < data->philosphers)
		pthread_detach(data->philosophers[i++].philosopher);
}
