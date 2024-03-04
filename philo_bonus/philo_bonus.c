/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/04 22:28:01 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <sys/semaphore.h>

void	*_main(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->sem_forks);
		print_state(philo, TAKING_FORK);
		sem_wait(philo->sem_forks);
		print_state(philo, TAKING_FORK);
		print_state(philo, EATING);
		_usleep(philo->t_2_e);
		sem_post(philo->sem_forks);
		sem_post(philo->sem_forks);
		print_state(philo, SLEAPING);
		_usleep(philo->t_2_s);
		print_state(philo, THINKING);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		philo_pid;

	if (check_input(argc, argv) == -1)
		return (_free(&data), -1);
	if (memory_init(&data, argv) == -1)
		return (_free(&data), -1);
	if (data_init(&data, argc, argv) == -1)
		return (_free(&data), -1);
	i = 0;
	while (i < data.n_philos)
	{
		philo_pid = fork();
		if (philo_pid == 0)
		{
			_main(&data.philos[i]);
			exit(0);
		}
		i++;
	}
	_free(&data);
}
