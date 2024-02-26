/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:15:21 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/26 10:15:07 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/philo.h" 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_size_t.h>


size_t	getime()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	_usleep(size_t mic_sec)
{
	size_t	tosleep;
	// tosleep = (getime() * 1000) + mic_sec;
	tosleep = getime();
	while ((getime() - tosleep) * 1000 < mic_sec);
	// while (getime() * 1000 < tosleep);
}

void	*philo_start(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (1)
	{
		ph_do(philo, "is thinking");
		pthread_mutex_lock(philo->left_fork);
		ph_do(philo, "has taken a fork");
		ph_do(philo, "is thinking");
		pthread_mutex_lock(philo->right_fork);
		ph_do(philo, "has taken a fork");
		ph_do(philo,"is eating");
		pthread_mutex_lock(philo->meal_time);
		philo->last_meal = getime();
		pthread_mutex_unlock(philo->meal_time);
		_usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ph_do(philo, "is sleeping");
		_usleep(philo->time_to_sleep * 1000);
	}
	return (NULL);
}

int	someone_dead(t_data data)
{
	size_t	last_meal;
	size_t	start_time;
	int		i;

	while (1)
	{
		i = 0;
		while (i < data.number_of_philos)
		{
			pthread_mutex_lock(data.philos[i].meal_time);
			last_meal = getime() - data.philos[i].last_meal;
			start_time = getime() - data.philos[i].start_time;
			if (last_meal >= data.philos[i].time_to_die)
			{
			pthread_mutex_unlock(data.philos[i].meal_time);
				pthread_mutex_lock(data.philos[i].pf);
				printf("%zu %d is dead\n", start_time, data.philos[i].number);
				pthread_mutex_destroy(data.philos[i].pf);
				return 1;
			}
			pthread_mutex_unlock(data.philos[i].meal_time);
			// pthread_mutex_unlock(data.philos[i].meal_time);
			i++;
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	input_checker(argc, argv);
	init_data(&data, argv);
	init_threads(&data);
	someone_dead(data);
	return (0);
}
