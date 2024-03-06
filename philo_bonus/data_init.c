/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:01:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/06 14:01:37 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/semaphore.h>
#include <unistd.h>

int	create_proccess(t_data *data)
{
	char	*sem_name;
	int		i;
	int		philo_pid;

	i = 0;
	while (i < data->n_philos)
	{
		data->philos[i].number = i + 1;
		philo_pid = fork();
		if (philo_pid == 0)
		{
			data->philos[i].philo_pid = getpid() - (data->n_philos + 1);
			sem_name = _itoa(i + 1);
			if (sem_name == NULL)
				return (-1);
			data->philos[i].sem_lock = sem_open(sem_name, O_CREAT, 0666, 1);
			_main(&data->philos[i]);
			exit(0);
		}
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

int	data_init(t_data *data, int argc, char **argv)
{
	size_t	start_time;
	int		i;

	i = 0;
	start_time = getime();
	data->n_philos = _atoi(argv[1]);
	while (i < data->n_philos)
	{
		data->philos[i].t_2_d = _atoi(argv[2]);
		data->philos[i].t_2_e = _atoi(argv[3]);
		data->philos[i].t_2_s = _atoi(argv[4]);
		data->philos[i].meal_count = -1;
		data->philos[i].start_time = start_time;
		data->philos[i].last_meal = start_time;
		data->philos[i].sem_printf = data->sem_printf;
		data->philos[i].sem_forks = data->sem_forks;
		data->philos[i].n_philos = data->n_philos;
		if (argc == 6)
			data->philos[i].meal_count = _atoi(argv[5]);
		i++;
	}
	return (0);
}

// while (waitpid(-1, *p, 0) != -1)
// {
// 	p = WEXITSTATUS(p);
// 	if (p == 30)
// 		kill();
// }

int	print_state(t_philo *philo, char *state)
{
	size_t	time;

	sem_wait(philo->sem_printf);
	time = getime() - philo->start_time;
	printf("%zu %d %s\n", time, philo->number, state);
	sem_post(philo->sem_printf);
	return (0);
}
