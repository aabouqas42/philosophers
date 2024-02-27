/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/27 13:42:42 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/philo.h"
#include <stdio.h>

void	*_main(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		print_state(philo, "is thinking");
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, "has taking a fork");
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, "are taking a fork");
		print_state(philo, "is eating");
		pthread_mutex_lock(&philo->meal_lock);
		philo->last_meal = getime();
		if (philo->meal_count != -1)
			philo->meal_count--;
		pthread_mutex_unlock(&philo->meal_lock);
		_usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		print_state(philo, "is sleeping");
		_usleep(philo->time_to_sleep);
		if (philo->meal_count == 0)
			break ;
	}
	return (NULL);
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
	somone_died(&data);
}
