/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/02 23:07:45 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *param)
{
	t_data	*data;
	size_t	time;
	int		meal;
	int		i;
	
	data = (t_data *)param;
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
				// pthread_mutex_lock(&data->printf);
				data->someone_died = 1;
				printf("%zu %d is died\n", time, data->philos[i].number);
				return (0);
			}
			i++;
		}
	}
	return (0);
}
