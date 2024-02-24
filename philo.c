/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:15:21 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/24 20:47:00 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/philo.h" 
#include <pthread.h>
#include <stdio.h>


size_t	getime()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	_usleep(size_t mic_sec)
{
	size_t	tosleep;
	tosleep = (getime() * 1000) + mic_sec + 1;
	while (getime() * 1000 < tosleep);
}

void	*philo_start(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (1)
	{
		// printf("%d <%p, %p>\n", philo->number, philo->left_fork, philo->right_fork);
		ph_do(philo, "is thinking");
		pthread_mutex_unlock(philo->pf);
		pthread_mutex_lock(philo->left_fork);
		ph_do(philo, "is thinking");
		pthread_mutex_lock(philo->right_fork);
		ph_do(philo, "has taken a fork");
		ph_do(philo,"is eating");
		usleep(philo->time_to_eat * 1000);
		philo->last_meal_time = getime();
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ph_do(philo, "is sleeping");
		usleep(philo->time_to_sleep * 1000);
	}
	return (NULL);
}

int	someone_dead(t_data data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data.philosphers)
		{
			// printf("%zu\n", getime() - data.philosophers[i].last_meal_time);
			if (getime() - data.philosophers[i].last_meal_time >= data.philosophers[i].time_to_die + 10)
			{
				printf("%zu %d is dead\n", getime() - data.philosophers[i].last_meal_time, data.philosophers[i].number);
				return 1;
			}
			i++;
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;
	
	input_checker(argc, argv);
	init_data(&data, argv);
	init_threads(&data);
	// someone_dead(data);
	i = 0;
	while (i < data.philosphers)
		pthread_detach(data.philosophers[i++].philosopher);
	return (0);
}
