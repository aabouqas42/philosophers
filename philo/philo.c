/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/08 11:03:42 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	*_main(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->printf);
		if (*philo->died)
			return (pthread_mutex_unlock(philo->printf), NULL);
		pthread_mutex_unlock(philo->printf);
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
		return (-1);
	if (memory_init(&data, argv) == -1)
		return (-1);
	if (mutex_init(&data) == -1)
		return (_free(&data), -1);
	data_init(&data, argc, argv);
	if (create_threads(&data) == -1)
		return (-1);
	int i = 0;
	monitor(&data);
	while (i < data.numof_philos)
	{
		pthread_join(data.philos[i].philo, NULL);
		i++;
	}
	_free(&data);
}
