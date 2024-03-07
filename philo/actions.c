/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:27:59 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/08 00:45:55 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeping(t_philo *philo)
{
	print_state(philo, SLEAPING);
	_usleep(philo->sleep_time, philo);
	return (0);
}

int	taking_a_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_state(philo, TAKING_FORK);
	pthread_mutex_lock(philo->right_fork);
	print_state(philo, TAKING_FORK);
	return (0);
}

int	eating(t_philo *philo)
{
	print_state(philo, EATING);
	pthread_mutex_lock(&philo->lock);
	philo->last_meal = getime();
	philo->meal_count -= (philo->meal_count != -1);
	pthread_mutex_unlock(&philo->lock);
	_usleep(philo->eat_time, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	thinking(t_philo *philo)
{
	print_state(philo, THINKING);
	return (0);
}
