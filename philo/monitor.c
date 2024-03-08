/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/08 16:25:53 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	someone_death(t_data *data, int i)
{
	int	time;

	time = getime() - data->philos[i].last_meal;
	if (time >= data->philos[i].die_time && data->philos[i].meal_count)
	{
		pthread_mutex_lock(data->philos[i].printf);
		data->died = 1;
		printf("%d %d died\n", time, data->philos[i].id);
		pthread_mutex_unlock(data->philos[i].printf);
		if (data->numof_philos == 1)
			pthread_mutex_unlock(data->philos[i].right_fork);
		return (1);
	}
	return (0);
}

int	monitor(t_data *data)
{
	t_philo	*philo;
	int		meal;
	int		i;

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
			if (someone_death(data, i))
				return (pthread_mutex_unlock(&philo->lock), 0);
			pthread_mutex_unlock(&philo->lock);
		}
	}
	return (0);
}
