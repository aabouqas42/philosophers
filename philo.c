/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/02 23:09:33 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*_main(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->number % 2)
		_usleep(100);
	while (1)
	{
		if (*philo->someone_died)
			return (NULL);
		eating(philo);
		if (philo->meal_count == 0)
			return (NULL);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
void leak()
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv) == -1)
		return (-1);
	memory_init(&data, argv);
	data_init(&data, argc, argv);
	forks_init(&data);
	create_threads(&data);
}
