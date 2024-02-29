/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:25:47 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/29 18:53:47 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	print_state(philo, THINKING);
	pthread_mutex_lock(philo->right_fork);
	print_state(philo, TAKING_FORK);
	print_state(philo, THINKING);
	pthread_mutex_lock(philo->left_fork);
	print_state(philo, TAKING_FORK);
}
void	eating(t_philo *philo)
{
	print_state(philo, EATING);
	philo->last_meal = getime();
	if (philo->meal_count != -1)
		philo->meal_count--;
	_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeping(t_philo *philo)
{
	print_state(philo, SLEAPING);
	_usleep(philo->time_to_sleep);
}
