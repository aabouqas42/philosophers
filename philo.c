/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/03 17:20:12 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/philo.h"

void	*_main(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, TAKING_FORK);
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, TAKING_FORK);
		print_state(philo, EATING);
		pthread_mutex_lock(philo->lock);
		philo->last_meal = getime();
		philo->meal_count -= (philo->meal_count != -1);
		pthread_mutex_unlock(philo->lock);
		_usleep(philo->t_2_e);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (philo->meal_count == 0)
			return (NULL);
		print_state(philo, SLEAPING);
		_usleep(philo->t_2_s);
		print_state(philo, THINKING);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv) == -1)
		return (_free(&data), -1);
	if (memory_init(&data, argv) == -1)
		return (_free(&data), -1);
	if (data_init(&data, argc, argv) == -1)
		return (_free(&data), -1);
	forks_init(&data);
	if (create_threads(&data) == -1)
		return (_free(&data), -1);
	monitor(&data);
	_free(&data);
}
