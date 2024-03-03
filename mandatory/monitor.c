/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/03 17:10:08 by aabouqas         ###   ########.fr       */
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
		i = -1;
		meal = 0;
		while (++i < data->n_philos)
		{
			pthread_mutex_lock(&data->lock);
			time = getime() - data->philos[i].last_meal;
			meal += (data->philos[i].meal_count == 0);
			pthread_mutex_unlock(&data->lock);
			if (meal == data->n_philos)
				return (0);
			if (time >= data->philos[i].t_2_d && data->philos[i].meal_count)
			{
				pthread_mutex_lock(&data->printf);
				printf("%zu %d is died\n", time, data->philos[i].number);
				return (_usleep(100), 0);
			}
		}
	}
	return (0);
}
