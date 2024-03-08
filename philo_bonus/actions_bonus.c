/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:27:59 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/08 18:52:20 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	sleeping(t_philo *philo)
{
	print_state(philo, SLEAPING);
	_usleep(philo->sleep_time);
	return (0);
}

int	taking_a_fork(t_philo *philo)
{
	sem_wait(philo->sem_forks);
	print_state(philo, TAKING_FORK);
	sem_wait(philo->sem_forks);
	print_state(philo, TAKING_FORK);
	return (0);
}

int	eating(t_philo *philo)
{
	print_state(philo, EATING);
	_usleep(philo->eat_time);
	sem_post(philo->sem_forks);
	sem_post(philo->sem_forks);
	sem_wait(philo->sem_lock);
	philo->last_meal = getime();
	philo->meal_count -= (philo->meal_count != -1);
	if (philo->meal_count == 0)
	{
		sem_post(philo->sem_lock);
		exit(0);
	}
	sem_post(philo->sem_lock);
	return (0);
}

int	thinking(t_philo *philo)
{
	print_state(philo, THINKING);
	return (0);
}
