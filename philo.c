/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:15:21 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/21 13:51:12 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/philo.h" 

void	*philo_start(void *arg)
{
	t_philos	*philosopher;

	philosopher = (t_philos *)arg;
	while (1)
	{
		printf("philo number : %d is thinking...\n", philosopher->number);
		pthread_mutex_lock(philosopher->left_fork);
		pthread_mutex_lock(philosopher->right_fork);
		printf("philo number : %d is eating...\n", philosopher->number);
		usleep(philosopher->time_to_eat * 1000);
		pthread_mutex_unlock(philosopher->left_fork);
		pthread_mutex_unlock(philosopher->right_fork);
		printf("philo number : %d is sleeping...\n", philosopher->number);
		usleep(philosopher->time_to_sleep * 1000);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init_data(&data, argv);
	init_threads(&data);
	free (data.philosophers);
	free (data.forks);
	return (0);
}
