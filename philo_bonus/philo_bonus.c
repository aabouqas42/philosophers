/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/05 11:50:17 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <sys/_types/_size_t.h>
#include <sys/semaphore.h>
#include <sys/wait.h>
#include <unistd.h>

void	*_main(void *arg)
{
	t_data	*philo;

	philo = (t_data *)arg;
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
	if (data_init(&data, argc, argv) == -1)
		return (_free(&data), -1);
	i = 0;
	// sem_wait(data.sem_printf);
	printf("%d\n",  data.sem_printf);
	unlink("/sem_printf");
	sem_close(data.sem_printf);
	// sem_wait(data.sem_printf);
	// printf("%d\n", n);
	// printf("%d\n", sem_wait(data.sem_printf));
	// printf("%d\n", sem_wait(data.sem_printf));
	// while (i < data.n_philos)
	// {
	// 	data.number = i + 1;
	// 	philo_pid = fork();
	// 	if (philo_pid == 0)
	// 	{
	// 		// printf("[%d]\n", i);
	// 		_main(&data);
	// 		exit(0);
	// 	}
	// 	data.philo_pid = philo_pid - (data.n_philos + 1);
	// 	i++;
	// }
	// while(waitpid(-1, NULL, 0));
	_free(&data);
}
