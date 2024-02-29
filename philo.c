/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/29 21:50:49 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/philo.h"
#include <pthread.h>
#include <unistd.h>

void	*_main(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		print_state(philo, THINKING);
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, TAKING_FORK);
		print_state(philo, THINKING);
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, TAKING_FORK);
		print_state(philo, EATING);
		_usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		print_state(philo, SLEAPING);
		_usleep(philo->time_to_sleep);
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
}
