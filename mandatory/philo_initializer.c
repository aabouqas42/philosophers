/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:31:01 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/21 12:43:42 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **argv)
{
	int	i;

	data->philosphers = _atoi(argv[1]);
	data->philos = malloc (sizeof(t_philos) * data->philosphers);
	if (data->philos == NULL)
		return (-1);
	i = 0;
	while (i < data->philosphers)
	{
		data->philos[i].time_to_die = _atoi(argv[2]);
		data->philos[i].time_to_eat = _atoi(argv[3]);
		data->philos[i].time_to_sleep = _atoi(argv[4]);
		data->philos[i].philo_id = i + 1;
		i++;
	}
	return (0);
}

void	init_threads(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc (sizeof(t_fork) * data->philosphers);
	while (i < data->philosphers)
		pthread_mutex_init(&data->forks[i++].fork, NULL);
	data->philos[0].left_fork = &data->forks[data->philosphers - 1];
	data->philos[0].right_fork = &data->forks[0];
	i = 1;
	while (i < data->philosphers)
	{
		data->philos[i].left_fork = &data->forks[i - 1];
		data->philos[i].right_fork = &data->forks[i];
		i++;
	}
	i = 0;
	while (i < data->philosphers)
	{
		pthread_create(&data->philos[i].thread, NULL, philo_start, &data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->philosphers)
		pthread_join (data->philos[i++].thread, NULL);
}
