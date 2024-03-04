/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/04 19:59:26 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_size_t.h>
#include <sys/fcntl.h>
#include <sys/semaphore.h>

void	*_main(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		print_state(philo, TAKING_FORK);
		print_state(philo, TAKING_FORK);
		print_state(philo, EATING);
		_usleep(philo->t_2_e);
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
	// monitor(&data);
	i = 0;
	int *s = sem_open("/sem", O_CREAT | O_RDWR, 0666, 1);
	sem_unlink("/sem");
	sem_post(s);
	sem_wait(s);
	// printf("[%d]\n", (int)*s);
	// while (1);
	// sem_post(s);
	// printf("[%p]\n", s);
	// while (i < data.n_philos)
	// {
	// 	philo_pid = fork();
	// 	if (philo_pid == 0)
	// 	{
	// 		_main(&data.philos[i]);
	// 		exit(0);
	// 	}
	// 	i++;
	// }
	_free(&data);
}
