/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:01:11 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/04 18:55:09 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <sys/semaphore.h>
#include <sys/wait.h>

void	forks_init(t_data *data)
{
	int	i;

	// data->philos[0].left_fork = &data->forks[data->n_philos - 1];
	// data->philos[0].right_fork = &data->forks[0];
	// i = 1;
	// while (i < data->n_philos)
	// {
	// 	data->philos[i].left_fork = &data->forks[i - 1];
	// 	data->philos[i].right_fork = &data->forks[i];
	// 	i++;
	// }
}

int	data_init(t_data *data, int argc, char **argv)
{
	size_t	start_time;
	sem_t	sem;
	int		i;

	start_time = getime();
	i = 0;
	while (i < data->n_philos)
	{
		data->philos[i].number = i + 1;
		data->philos[i].start_time = start_time;
		data->philos[i].last_meal = start_time;
		data->philos[i].t_2_d = _atoi(argv[2]);
		data->philos[i].t_2_e = _atoi(argv[3]);
		data->philos[i].t_2_s = _atoi(argv[4]);
		if (argc == 6)
			data->philos[i].meal_count = _atoi(argv[5]);
		else
			data->philos[i].meal_count = -1;
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

	time = getime() - philo->start_time;
	printf("%zu %d %s\n", time, philo->number, state);
	return (0);
}
