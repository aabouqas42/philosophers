/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/03 13:51:30 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	monitor(t_data *data)
{
	size_t	time;
	int		meal;
	int		i;
	
	while (1)
	{
		(i = 0, meal = 0);
		while (i < data->n_philos)
		{
			pthread_mutex_lock(&data->lock);
			time = getime() - data->philos[i].last_meal;
			pthread_mutex_unlock(&data->lock);
			if (time >= data->philos[i].time_to_die)
			{
				pthread_mutex_lock(&data->dead_mutex);
				data->someone_died = 1;
				pthread_mutex_unlock(&data->dead_mutex);
				printf("\033[31m%zu %d is died\n\033[0m", time, data->philos[i].number);
				_usleep(500);
				return (0);
			}
			i++;
		}
	}
	return (0);
}
