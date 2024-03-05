/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/05 17:22:06 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	kill_all(t_data data)
{
	int	i;

	i = data.philo_pid;
	while (i <= i + data.n_philos)
	{
		if (i != getpid())
			kill (i, SIGINT);
		i++;
	}
	return (0);
}

void	*monitor(void *data)
{
	t_data	*philo;
	int	time;
	int	meal;
	int	i;

	philo = (t_data *)data;
	while (1)
	{
		time = getime() - philo->last_meal;
		if (philo->meal_count == 0)
			return (0);
		if (time >= philo->t_2_d && philo->meal_count != 0)
		{
			sem_wait(philo->sem_printf);
			printf("%d %d is died\n", time, philo->number);
			kill_all(*philo);
			exit(0);
			return (NULL);
		}
	}
	return (0);
}
