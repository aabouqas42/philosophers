/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:01:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/09 19:40:46 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_init(t_data *data)
{
	int	i;

	data->philos[0].left_fork = &data->forks[data->numof_philos - 1];
	data->philos[0].right_fork = &data->forks[0];
	i = 1;
	while (i < data->numof_philos)
	{
		data->philos[i].left_fork = &data->forks[i - 1];
		data->philos[i].right_fork = &data->forks[i];
		i++;
	}
}

int	create_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->numof_philos)
	{
		philo = &data->philos[i];
		if (pthread_create(&philo->philo, NULL, _main, &data->philos[i]) != 0)
			return (_free(data), -1);
		if (i % 2 == 0)
			usleep(100);
		i++;
	}
	return (0);
}

void	data_init(t_data *data, int argc, char **argv)
{
	size_t	start_time;
	int		i;

	start_time = getime();
	i = 0;
	data->died = 0;
	while (i < data->numof_philos)
	{
		data->philos[i].die_time = _atoi(argv[2]);
		data->philos[i].eat_time = _atoi(argv[3]);
		data->philos[i].sleep_time = _atoi(argv[4]);
		data->philos[i].id = i + 1;
		data->philos[i].start = start_time;
		data->philos[i].last_meal = start_time;
		data->philos[i].died = &data->died;
		data->philos[i].meal_count = -1;
		if (argc == 6)
			data->philos[i].meal_count = _atoi(argv[5]);
		i++;
	}
	forks_init(data);
}

int	print_state(t_philo *philo, char *state)
{
	pthread_mutex_lock(philo->printf);
	if (*philo->died == 0)
		printf("%zu %d %s\n", getime() - philo->start, philo->id, state);
	pthread_mutex_unlock(philo->printf);
	return (0);
}
