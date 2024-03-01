/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/01 12:25:56 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	monitor(t_data *data)
{
	size_t	time;
	int		meal;
	int		i;
	i = 0;
	while (1)
	{
		if (i == data->n_philos)
			(i = 0, meal = 0);
		pthread_mutex_lock(data->philos[i].lock);
		time = getime() - data->philos[i].last_meal;
		if (data->philos[i].meal_count == 0)
			meal++;
		if (meal == data->n_philos)
			return (0);
		pthread_mutex_unlock(data->philos[i].lock);
		if (time >= data->philos[i].time_to_die)
		{
			pthread_mutex_lock(&data->printf);
			time = getime() - data->philos[i].start_time;
			printf("%zu %d is died\n", time, data->philos[i].number);
			return (1);
		}
		i++;
	}
	return (0);
}