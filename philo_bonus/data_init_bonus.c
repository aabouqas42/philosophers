/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:01:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/08 11:57:57 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	data_init(t_data *data, int argc, char **argv, int id)
{
	int		i;
	int		meal_count;

	i = 0;
	meal_count = -1;
	if (argc == 6)
		meal_count = _atoi(argv[5]);
	data->n_philos = _atoi(argv[1]);
	data->philo.die_time = _atoi(argv[2]);
	data->philo.eat_time = _atoi(argv[3]);
	data->philo.sleep_time = _atoi(argv[4]);
	data->philo.start_time = data->start_time;
	data->philo.last_meal = data->start_time;
	data->philo.sem_printf = data->sem_printf;
	data->philo.sem_forks = data->sem_forks;
	data->philo.meal_count = meal_count;
	data->philo.id = id;
	return (0);
}

int	create_proccess(t_data *data, int argc, char** argv)
{
	int		i;
	int		philo_pid;

	i = 0;
	data->start_time = getime();
	while (i < data->n_philos)
	{
		philo_pid = fork();
		if (philo_pid == 0)
		{
			data_init(data, argc, argv, i + 1);
			_main(&data->philo);
			exit(0);
		}
		data->ids[i] = philo_pid;
		if (philo_pid == -1)
			return (_puts("Unexpected Error\n", 2), -1);
		i++;
	}
	return (0);
}

char	*_itoa(int number)
{
	char	*str;
	int		len;
	int		n;

	len = 0;
	if (number <= 0)
		return (NULL);
	n = number;
	while (n)
		(n /= 10, len++);
	str = malloc (len + 1);
	if (str == NULL)
		return (NULL);
	if (str == NULL)
		return (NULL);
	n = 0;
	str[len--] = '\0';
	while (number)
	{
		str[len] = "0123456789"[number % 10];
		number /= 10;
		len--;
	}
	return (str);
}

int	print_state(t_philo *philo, char *state)
{
	size_t	time;

	sem_wait(philo->sem_printf);
	time = getime() - philo->start_time;
	printf("%zu %d %s\n", time, philo->id, state);
	sem_post(philo->sem_printf);
	return (0);
}