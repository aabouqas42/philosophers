/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:25 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/05 23:14:01 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>

void	_free(t_data *data)
{
	// free (data->philosophers);
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
	data->n_philos = _atoi(argv[1]);
	data->sem_printf = sem_open("sem_printf", O_CREAT, 0666, 1);
	data->sem_forks = sem_open("sem_forks", O_CREAT, 0666, data->n_philos);
	data->philos = malloc (data->n_philos * sizeof(t_philo));
	if (data->philos == NULL)
		return (_puts("Unexpected Error\n", 2), -1);
	return (0);
}
