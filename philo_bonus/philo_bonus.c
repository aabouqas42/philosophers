/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/05 14:16:32 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	_main(t_data *philo)
{
	pthread_t	thread;
	pthread_create(&thread, NULL, monitor, philo);
	pthread_detach(thread);
	while (1)
	{
		sem_wait(philo->sem_forks);
		print_state(philo, TAKING_FORK);
		sem_wait(philo->sem_forks);
		print_state(philo, TAKING_FORK);
		print_state(philo, EATING);
		// philo->last_meal = getime();
		_usleep(philo->t_2_e);
		sem_post(philo->sem_forks);
		sem_post(philo->sem_forks);
		print_state(philo, SLEAPING);
		_usleep(philo->t_2_s);
		print_state(philo, THINKING);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		philo_pid;

	data.ppid = getpid();
	if (check_input(argc, argv) == -1)
		return (_free(&data), -1);
	if (data_init(&data, argc, argv) == -1)
		return (_free(&data), -1);
	if (create_proccess(&data) == -1)
		return (-1);
	while(waitpid(-1, NULL, 0));
}
