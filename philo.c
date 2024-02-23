/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:15:21 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/23 17:23:20 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/philo.h" 
#include <stdio.h>
#include <sys/_types/_size_t.h>
#include <unistd.h>


size_t	getime()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

#define hh "adsads"

void	_usleep(size_t mic_sec)
{
	size_t	tosleep;
	tosleep = (getime() * 1000) + mic_sec;
	while (getime() * 1000 != tosleep);
}

void	*philo_start(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->lock_printf);
		printf("%zu : %d is thinking\n",getime() - philo->start_time, philo->number);
		pthread_mutex_unlock(&philo->lock_printf);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&philo->lock_printf);
		printf("%zu %d has taken a fork\n",getime() - philo->start_time, philo->number);
		pthread_mutex_unlock(&philo->lock_printf);
		pthread_mutex_lock(&philo->lock_printf);
		printf("%zu %d is eating\n", getime() - philo->start_time ,philo->number);
		pthread_mutex_unlock(&philo->lock_printf);
		philo->last_meal_time = getime();
		_usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(&philo->lock_printf);
		printf("%zu %d is sleeping\n",getime() - philo->start_time, philo->number);
		pthread_mutex_unlock(&philo->lock_printf);
		_usleep(philo->time_to_sleep);
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
			if (getime() - data.philosophers[i].last_meal_time >= data.philosophers[i].time_to_die)
			{
				pthread_mutex_lock(&data.philosophers[i].lock_printf);
				printf("%zu %d is dead\n",getime() - data.philosophers[i].start_time, data.philosophers[i].number);
				pthread_mutex_unlock(&data.philosophers[i].lock_printf);
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

	printf(hh"jjj");

	// init_data(&data, argv);
	// init_threads(&data);
	// // someone_dead(data);
	// free (data.philosophers);
	// free (data.forks);
	// _usleep(1);
	// printf("hello :)\n");
	return (0);
}
