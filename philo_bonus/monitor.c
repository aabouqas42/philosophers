/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/05 23:47:09 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <sys/semaphore.h>

int	kill_all(t_philo *philo)
{
	int	i;

	i = philo->philo_pid;
	while (i <= i + philo->n_philos)
	{
		if (i != getpid())
			kill (i, SIGINT);
		i++;
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	int	time;
	int	meal;
	int	i;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->sem_lock);
		time = getime() - philo[i].last_meal;
		if (philo->meal_count == 0)
			return (0);
		if (time >= philo->t_2_d && philo->meal_count != 0)
		{
			sem_wait(philo->sem_printf);
			time = getime() - philo[i].start_time;
			printf("%d %d is died\n", time, philo->number);
			kill_all(philo);
			exit(0);
		}
		sem_post(philo->sem_lock);
	}
	return (0);
}
