/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:25 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/09 16:27:25 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	_free(t_data *data)
{
	int		i;
	char	*number;

	sem_close(data->sem_forks);
	i = 0;
	while (i < data->numof_philos)
	{
		number = _itoa(i + 3);
		sem_close(data->sem_locks[i]);
		sem_unlink(number);
		free(number);
		i++;
	}
	free (data->sem_locks);
	free (data->ids);
}

void	memory_init(t_data *data, char **argv)
{
	char	*number;
	int		i;

	i = 0;
	while (i < 200)
	{
		number = _itoa(i + 3);
		if (number == NULL)
			(_puts("Unexpected Error\n", 2), exit(0));
		sem_unlink(number);
		free(number);
		i++;
	}
	sem_unlink("sem_printf");
	sem_unlink("sem_forks");
	data->numof_philos = _atoi(argv[1]);
	data->sem_printf = sem_open("sem_printf", O_CREAT, 0666, 1);
	data->sem_forks = sem_open("sem_forks", O_CREAT, 0666, data->numof_philos);
	data->ids = malloc (data->numof_philos * sizeof(int));
	if (data->ids == NULL)
		(_puts("Unexpected Error\n", 2), exit(-1));
	data->sem_locks = malloc (sizeof(sem_t *) * data->numof_philos);
	if (data->sem_locks == NULL)
		(_puts("Unexpected Error\n", 2), free (data->ids), exit(-1));
}
