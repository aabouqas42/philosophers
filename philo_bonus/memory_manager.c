/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:25 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/04 18:40:19 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	_free(t_data *data)
{
	int	i;

	free (data->forks);
	free (data->philos);
}

int	memory_init(t_data *data, char **argv)
{
	int		i;

	data->n_philos = _atoi(argv[1]);
	i = 0;
	data->philos = NULL;
	data->forks = NULL;
	data->philos = malloc (sizeof(t_philo) * data->n_philos);
	if (data->philos == NULL)
		return (_puts("Unexpected Error\n", 2), -1);
	return (0);
}
