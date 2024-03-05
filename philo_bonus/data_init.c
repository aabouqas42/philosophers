/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:01:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/05 17:22:53 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <unistd.h>

int	create_proccess(t_data *data)
{
	int			i;
	int			philo_pid;

	i = 0;
	while (i < data->n_philos)
	{
		data->number = i + 1;
		philo_pid = fork();
		if (philo_pid == 0)
		{
			_main(data);
			exit(0);
		}
		if (philo_pid == -1)
			return (_puts("Unexpected Error\n", 2), -1);
		data->philo_pid = philo_pid - (data->n_philos + 1);
		i++;
	}
	return (0);
}

int	data_init(t_data *data, int argc, char **argv)
{
	size_t	start_time;
	int		i;

	data->n_philos = _atoi(argv[1]);
	data->t_2_d = _atoi(argv[2]);
	data->t_2_e = _atoi(argv[3]);
	data->t_2_s = _atoi(argv[4]);
	start_time = getime();
	sem_unlink("sem_printf");
	sem_unlink("sem_forks");
	data->sem_printf = sem_open("sem_printf", O_CREAT, 0666, 1);
	data->sem_forks = sem_open("sem_forks", O_CREAT, 0666, data->n_philos);
	data->meal_count = -1;
	data->start_time = start_time;
	data->last_meal = start_time;
	data->sem_printf = data->sem_printf;
	data->sem_forks = data->sem_forks;
	if (argc == 6)
		data->meal_count = _atoi(argv[5]);
	return (0);
}

// while (waitpid(-1, *p, 0) != -1)
// {
// 	p = WEXITSTATUS(p);
// 	if (p == 30)
// 		kill();
// }

int	print_state(t_data *philo, char *state)
{
	size_t	time;

	sem_wait(philo->sem_printf);
	time = getime() - philo->start_time;
	printf("%zu %d %s\n", time, philo->number, state);
	sem_post(philo->sem_printf);
	return (0);
}
