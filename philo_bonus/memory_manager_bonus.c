/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:25 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/08 11:58:21 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	_free(t_data *data)
{
	free (data->philosophers);
}

int	memory_init(t_data *data, char **argv)
{
	char	*number;
	int		i;

	i = 0;
	while (i < 200)
	{
		number = _itoa(i + 1);
		if (number == NULL)
			return (-1);
		sem_unlink(number);
		free(number);
		i++;
	}
	sem_unlink("sem_printf");
	sem_unlink("sem_forks");
	sem_unlink("sem_lock");
	data->n_philos = _atoi(argv[1]);
	data->sem_printf = sem_open("sem_printf", O_CREAT, 0666, 1);
	data->sem_lock = sem_open("sem_lock", O_CREAT, 0666, 1);
	data->sem_forks = sem_open("sem_forks", O_CREAT, 0666, data->n_philos);
	data->ids = malloc (data->n_philos * sizeof(int));
	if (data->ids == NULL)
		return (_puts("Unexpected Error\n", 2), -1);
	return (0);
}
