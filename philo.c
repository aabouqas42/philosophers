/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/03 13:50:39 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*_main(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->number % 2)
		_usleep(100);
	while (1)
	{
		pthread_mutex_lock(philo->dead_mutex);
		if (*philo->someone_died)
			return (pthread_mutex_unlock(philo->dead_mutex), NULL);
		pthread_mutex_unlock(philo->dead_mutex);
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, TAKING_FORK);
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, TAKING_FORK);
		print_state(philo, EATING);
		pthread_mutex_lock(philo->lock);
		philo->last_meal = getime();
		philo->meal_count -= (philo->meal_count != -1);
		pthread_mutex_unlock(philo->lock);
		_usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (philo->meal_count == 0)
			return (NULL);
		sleeping(philo);
		print_state(philo, THINKING);
	}
	return (NULL);
}
void leak()
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv) == -1)
		return (-1);
	memory_init(&data, argv);
	data_init(&data, argc, argv);
	forks_init(&data);
	create_threads(&data);
	monitor(&data);
}
