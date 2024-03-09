/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:25 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/09 13:00:24 by aabouqas         ###   ########.fr       */
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
		sem_unlink(number);
		free(number);
		i++;
	}
	free (data->ids);
}

int	memory_init(t_data *data, char **argv)
{
	char	*number;
	int		i;

	i = 0;
	while (i < 200)
	{
		number = _itoa(i + 3);
		if (number == NULL)
			return (-1);
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
		return (_puts("Unexpected Error\n", 2), -1);
	return (0);
}
