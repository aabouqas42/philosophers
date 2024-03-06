/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/06 20:24:03 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	someone_death(t_philo *philo)
{
	size_t	time;

	time = getime() - philo->last_meal;
	if (time >= (size_t) philo->die_time && philo->meal_count)
	{
		pthread_mutex_lock(philo->printf);
		printf("%zu %d is died\n", time, philo->id);
		return (1);
	}
	return (0);
}

int	monitor(t_data *data)
{
	t_philo	*philo;
	int	meal;
	int	i;

	while (1)
	{
		i = -1;
		meal = 0;
		while (++i < data->numof_philos)
		{
			philo = &data->philos[i];
			pthread_mutex_lock(&philo->lock);
			meal += (philo->meal_count == 0);
			if (meal == data->numof_philos)
				return (0);
			if (someone_death(philo))
				return (0);
			pthread_mutex_unlock(&philo->lock);
		}
	}
	return (0);
}
