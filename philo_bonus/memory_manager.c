/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:25 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/05 10:47:25 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	_free(t_data *data)
{
	// free (data->philosophers);
}

// int	memory_init(t_data *data, char **argv)
// {
// 	data->n_philos = _atoi(argv[1]);
// 	data->philosophers = malloc (data->n_philos * sizeof(t_data));
// 	if (data->philosophers == NULL)
// 		return (_puts("Unexpected Error\n", 2), -1);
// 	return (0);
// }
