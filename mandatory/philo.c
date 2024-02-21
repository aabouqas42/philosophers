/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:15:21 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/21 12:47:10 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

void	*philo_start(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (1)
	{
		printf("philo number : %d is thinking...\n", philo->philo_id);
		pthread_mutex_lock(&philo->left_fork->fork);
		pthread_mutex_lock(&philo->right_fork->fork);
		printf("philo number : %d is eating...\n", philo->philo_id);
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->left_fork->fork);
		pthread_mutex_unlock(&philo->right_fork->fork);
		printf("philo number : %d is sleeping...\n", philo->philo_id);
		usleep(philo->time_to_sleep * 1000);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init_data(&data, argv);
	init_threads(&data);
	free (data.philos);
	free (data.forks);
	return (0);
}
