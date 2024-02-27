/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/27 13:56:35 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	is_finish_eating(t_data *data)
{
	int	i;
	int	meals;

	i = 0;
	meals = 0;
	while (i < data->number_of_philos)
	{
		if (data->philos[i].meal_count == 0)
			meals++;
		i++;
	}
	return (meals == data->number_of_philos);
}

int	somone_died(t_data *data)
{
	size_t	time;
	int		i;

	while (1)
	{
		i = 0;
		while (i < data->number_of_philos)
		{
			pthread_mutex_lock(&data->philos[i].meal_lock);
			time = getime() - data->philos[i].last_meal;
			if (is_finish_eating(data))
				return (0);
			if (time >= data->philos[i].time_to_die)
			{
				pthread_mutex_lock(&data->pf);
				printf("%zu %d is died\n", time, data->philos[i].number);
				return (1);
			}
			pthread_mutex_unlock(&data->philos[i].meal_lock);
			i++;
		}
	}
	return (0);
}
