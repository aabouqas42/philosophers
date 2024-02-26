/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:31:01 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/25 22:13:48 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **argv)
{
	int		i;
	size_t	start_time;

	data->number_of_philos = _atoi(argv[1]);
	data->philos = malloc (sizeof(t_philos) * data->number_of_philos);
	if (data->philos == NULL)
		return (-1);
	pthread_mutex_init(&data->pf, NULL);
	pthread_mutex_init(&data->meal_time_lock, NULL);
	start_time = getime();
	i = 0;
	while (i < data->number_of_philos)
	{
		data->philos[i].time_to_die = _atoi(argv[2]);
		data->philos[i].time_to_eat = _atoi(argv[3]);
		data->philos[i].time_to_sleep = _atoi(argv[4]);
		data->philos[i].number = i + 1;
		data->philos[i].last_meal = start_time;
		data->philos[i].start_time = start_time;
		data->philos[i].pf = &data->pf;
		data->philos[i].meal_time = &data->meal_time_lock;
		i++;
	}
	return (0);
}

void	init_threads(t_data *data)
{
	int	i;

	data->forks = malloc (sizeof(pthread_mutex_t) * data->number_of_philos);
	i = 0;
	while (i < data->number_of_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
	data->philos[0].left_fork = &data->forks[data->number_of_philos - 1];
	data->philos[0].right_fork = &data->forks[0];
	i = 1;
	while (i < data->number_of_philos)
	{
		data->philos[i].left_fork = &data->forks[i - 1];
		data->philos[i].right_fork = &data->forks[i];
		i++;
	}
	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_create(&data->philos[i].philo, NULL, philo_start, &data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->number_of_philos)
		pthread_detach(data->philos[i++].philo);
}
