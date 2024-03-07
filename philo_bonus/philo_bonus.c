/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/07 21:42:52 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	_main(t_philo *philo)
{
	pthread_t	thread;
	pthread_create(&thread, NULL, monitor, philo);
	pthread_detach(thread);
	while (1)
	{
		taking_a_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

void	kill_all(int *philos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		kill (philos[i], SIGINT);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	if (check_input(argc, argv) == -1)
		return (_free(&data), -1);
	if (memory_init(&data, argv) == -1)
		return (_free(&data), -1);
	if (create_proccess(&data, argc, argv) == -1)
		return (-1);
	ret = 0;
	while (waitpid(-1, &ret, 0) != -1)
	{
		ret = WEXITSTATUS(ret);
		if (ret == 3)
		{
			kill_all(data.ids, data.n_philos);
			exit(0);
		}
	}
}
