/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/28 19:21:32 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	somone_died(t_data *data)
{
	size_t	time;
	int		i;
	int	meals;

	while (1)
	{
		i = 0;
		meals = 0;
		while (i < data->number_of_philos)
		{
			pthread_mutex_lock(&data->philos[i].meal_lock);
			if (data->philos[i].meal_count == 0)
				meals++;
			time = getime() - data->philos[i].last_meal;
			if (time >= data->philos[i].time_to_die)
			{
				pthread_mutex_lock(&data->pf);
				printf("%zu %d is died\n", time, data->philos[i].number);
				return (1);
			}
			(pthread_mutex_unlock(&data->philos[i].meal_lock), i++);
		}
		if (meals == data->number_of_philos)
			return (pthread_mutex_lock(&data->pf), 1);
	}
	return (1);
}
