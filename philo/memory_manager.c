/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:25 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/07 11:27:51 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numof_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
		i++;
	}
	pthread_mutex_destroy(&data->printf);
	free (data->forks);
	free (data->philos);
}

int	mutex_init(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->printf, NULL))
		return (_free(data), _puts("Unexpected Error\n", 2), -1);
	while (i < data->numof_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (_free(data), _puts("Unexpected Error\n", 2), -1);
		if (pthread_mutex_init(&data->philos[i].lock, NULL))
			return (_free(data), _puts("Unexpected Error\n", 2), -1);
		data->philos[i].printf = &data->printf;
		i++;
	}
	return (0);
}

int	memory_init(t_data *data, char **argv)
{
	data->philos = NULL;
	data->forks = NULL;
	data->numof_philos = _atoi(argv[1]);
	data->philos = malloc (sizeof(t_philo) * data->numof_philos);
	if (data->philos == NULL)
		return (_puts("Unexpected Error\n", 2), -1);
	data->forks = malloc (sizeof(pthread_mutex_t) * data->numof_philos);
	if (data->forks == NULL)
		return (_free(data), _puts("Unexpected Error\n", 2), -1);
	return (0);
}
