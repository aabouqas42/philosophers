/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/07 11:43:40 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	someone_death(t_philo *philo, int *died)
{
	size_t	time;
	
	time = getime() - philo->last_meal;
	if (time >= (size_t) philo->die_time && philo->meal_count)
	{
		pthread_mutex_lock(philo->printf);
		*died = 1;
		pthread_mutex_unlock(philo->printf);
		printf("%zu %d died\n", time, philo->id);
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
			if (someone_death(philo, &data->died))
				return (pthread_mutex_unlock(&philo->lock), 0);
			pthread_mutex_unlock(&philo->lock);
		}
	}
	return (0);
}
