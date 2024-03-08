/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/07 20:17:14 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	someone_death(t_philo *philo)
{
	long	time;

	time = getime() - philo->last_meal;
	if (time >= philo->die_time && philo->meal_count != 0)
	{
		sem_wait(philo->sem_printf);
		printf("%zu %d died\n", time, philo->id);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		time;
	int		i;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->sem_lock);
		if (someone_death(philo))
			exit(3);
		sem_post(philo->sem_lock);
	}
	return (0);
}