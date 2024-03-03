/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/03 11:09:07 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

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
				pthread_mutex_lock(&data->printf);
				printf("\033[31m%zu %d is died\n", time, data->philos[i].number);
				_usleep(10);
				return (0);
			}
			i++;
		}
	}
	return (0);
}
