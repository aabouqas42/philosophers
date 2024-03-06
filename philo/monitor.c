/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/06 14:00:51 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/_types/_size_t.h>
#include <unistd.h>

size_t	get_last_meal_time(t_philo philo)
{
	size_t	time;

	time = 0;
	pthread_mutex_lock(&philo.meal_lock);
	time = getime() - philo.last_meal;
	pthread_mutex_unlock(&philo.meal_lock);
	return (time);
}

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
			time = get_last_meal_time(data->philos[i]);
			pthread_mutex_lock(&data->philos[i].meal_count_lock);
			meal += (data->philos[i].meal_count == 0);
			if (meal == data->n_philos)
				return (0);
			if (time >= data->philos[i].t_2_d && data->philos[i].meal_count)
			{
				pthread_mutex_lock(&data->printf);
				printf("%d %d is died\n", time, data->philos[i].number);
				return (_usleep(100), 0);
			}
			pthread_mutex_unlock(&data->philos[i].meal_count_lock);
		}
	}
	return (0);
}
