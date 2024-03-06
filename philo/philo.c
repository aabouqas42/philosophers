/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/06 20:01:58 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*_main(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(100);
	while (1)
	{
		taking_a_fork(philo);
		eating(philo);
		if (philo->meal_count == 0)
			return (NULL);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv) == -1)
		return (_free(&data), -1);
	if (memory_init(&data, argv) == -1)
		return (_free(&data), -1);
	if (mutex_init(&data) == -1)
		return (_free(&data), -1);
	if (data_init(&data, argc, argv) == -1)
		return (_free(&data), -1);
	forks_init(&data);
	if (create_threads(&data) == -1)
		return (_free(&data), -1);
	monitor(&data);
	_free(&data);
}

