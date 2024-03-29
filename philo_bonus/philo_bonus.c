/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/10 10:38:53 by aabouqas         ###   ########.fr       */
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
	exit(0);
}

void	kill_all(int *philos, int number_of_philos)
{
	int	i;

	i = 0;
	while (i < number_of_philos)
	{
		kill (philos[i], SIGINT);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	check_input(argc, argv);
	memory_init(&data, argv);
	if (create_proccess(&data, argc, argv) == -1)
		return (_free(&data), -1);
	ret = 0;
	while (waitpid(-1, &ret, 0) != -1)
	{
		ret = WEXITSTATUS(ret);
		if (ret == 3)
		{
			_free(&data);
			return (0);
		}
	}
	_free(&data);
}
