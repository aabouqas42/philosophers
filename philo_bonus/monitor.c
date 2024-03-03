/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/03 22:56:43 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	monitor(t_data *data)
{
	int	time;
	int	meal;
	int	i;

	while (1)
	{
		i = -1;
		meal = 0;
		while (++i < data->n_philos)
		{
			pthread_mutex_lock(&data->philos[i].lock);
			time = getime() - data->philos[i].last_meal;
			meal += (data->philos[i].meal_count == 0);
			if (meal == data->n_philos)
				return (0);
			if (time >= data->philos[i].t_2_d && data->philos[i].meal_count)
			{
				pthread_mutex_lock(&data->printf);
				printf("%d %d is died\n", time, data->philos[i].number);
				pthread_mutex_unlock(&data->philos[i].lock);
				return (_usleep(100), 0);
			}
			pthread_mutex_unlock(&data->philos[i].lock);
		}
	}
	return (0);
}
