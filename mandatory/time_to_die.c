/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:49 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/29 22:51:38 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	somone_died(t_data *data)
{
	size_t	time;
	int		meal;
	int		i;
	while (1)
	{
		if (i == data->n_philos)
			(i = 0, meal = 0);
		pthread_mutex_lock(data->philos[i].lock);
		pthread_mutex_unlock(data->philos[i].lock);
	}
	return (0);
}
