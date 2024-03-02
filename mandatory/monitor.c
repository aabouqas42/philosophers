/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/02 20:01:24 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor(t_data *data)
{
	size_t	time;
	int		meal;
	int		i;
	
	while (1)
	{
		pthread_mutex_lock(&data->printf);
		(i = 0, meal = 0);
		pthread_mutex_lock(&data->lock);
		while (i < data->n_philos)
		{
			time = getime() - data->philos[i].last_meal;
			if (time >= data->philos[i].time_to_die)
			{
				printf("%zu %d is died\n", time, data->philos[i].number);
				return (0);
			}
			i++;
		}
		pthread_mutex_unlock(&data->lock);
		pthread_mutex_unlock(&data->printf);
	}
	return (0);
}
