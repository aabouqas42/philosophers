/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:25:47 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/01 11:19:43 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking(t_philo *philo)
{
	if (print_state(philo, THINKING))
		return (1);
	pthread_mutex_lock(philo->left_fork);
	if (print_state(philo, TAKING_FORK))
		return (1);
	print_state(philo, THINKING);
	if (pthread_mutex_lock(philo->right_fork))
		return (1);
	if (print_state(philo, TAKING_FORK))
		return (1);
	return (0);
}
int	eating(t_philo *philo)
{
	if (print_state(philo, EATING))
		return (1);
	pthread_mutex_lock(philo->lock);
	philo->last_meal = getime();
	if (philo->meal_count != -1)
		philo->meal_count--;
	pthread_mutex_unlock(philo->lock);
	_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (print_state(philo, SLEAPING))
		return (1);
	_usleep(philo->time_to_sleep);
	return (0);
}
