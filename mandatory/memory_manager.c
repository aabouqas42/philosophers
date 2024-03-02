/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:25 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/02 12:08:10 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->printf);
	free (data->forks);
	free (data->philos);
}

int	memory_init(t_data *data, char **argv)
{
	int		i;

	data->n_philos = _atoi(argv[1]);
	data->philos = NULL;
	data->forks = NULL;
	data->philos = malloc (sizeof(t_philo) * data->n_philos);
	if (data->philos == NULL)
		return (_puts("Unexpected Error\n", 2), -1);
	data->forks = malloc (sizeof(pthread_mutex_t) * data->n_philos);
	if (data->forks == NULL)
		return (_free(data), _puts("Unexpected Error\n", 2), -1);
	if (pthread_mutex_init(&data->printf, NULL)
		|| pthread_mutex_init(&data->lock, NULL))
		return (_free(data), _puts("Unexpected Error\n", 2), -1);
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (_free(data), _puts("Unexpected Error\n", 2), -1);
		data->philos[i].printf = &data->printf;
		data->philos[i].lock = &data->lock;
		i++;
	}
	return (0);
}
