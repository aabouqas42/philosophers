/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:15:21 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/20 23:55:47 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 
#include <pthread.h>
#include <unistd.h>

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	_atoi(char *str)
{
	int	res;

	if (*str == '-')
		return (printf("Invalid input :)\n"), -1);
	if (*str == '+')
		str++;
	res = 0;
	while (*str)
	{
		if (!is_digit(*str))
			return (printf("Invalid input :)\n"), -1);
		res = res * 10 + *str - 48;
		str++;
	}
	return (res);
}

int	input_checker(int argc, char **argv)
{
	int	i;
	
	i = 1;
	if (argc < 5 || argc >= 7)
		return (printf("Invalid input :)\n"), -1);
	while (argv[i])
	{
		if (_atoi(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}


void	*philo_start(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while ()
	{
		printf("philo number : %d is thinking...\n", philo->philo_id);
		if (usleep())
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

void	init_threads(t_data *data)
{
	int	i;
	int	philos;

	i = 0;
	philos = data->philosphers;
	data->forks = malloc (sizeof(t_fork) * philos);
	while (i < philos)
		pthread_mutex_init(&data->forks[i++].fork, NULL);
	data->philos[0].left_fork = &data->forks[philos - 1];
	data->philos[0].right_fork = &data->forks[0];
	i = 1;
	while (i < philos)
	{
		data->philos[i].left_fork = &data->forks[i - 1];
		data->philos[i].right_fork = &data->forks[i];
		i++;
	}
	i = 0;
	while (i < philos)
	{
		pthread_create(&data->philos[i].thread, NULL, philo_start, &data->philos[i]);
		i++;
	}
	i = 0;
	while (i < philos)
		pthread_join (data->philos[i++].thread, NULL);
}

int	init_data(t_data *data, char **argv)
{
	int	i;

	data->philosphers = _atoi(argv[1]);
	data->philos = malloc (sizeof(t_philos) * data->philosphers);
	if (data->philos == NULL)
		return (-1);
	i = 0;
	while (i < data->philosphers)
	{
		data->philos[i].time_to_die = _atoi(argv[2]);
		data->philos[i].time_to_eat = _atoi(argv[3]);
		data->philos[i].time_to_sleep = _atoi(argv[4]);
		data->philos[i].philo_id = i + 1;
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init_data(&data, argv);
	init_threads(&data);
	return (0);
}
