/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:58:30 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/24 18:52:53 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_do(t_philos *philo, char *state)
{
	size_t	num;
	size_t	time;
	
	pthread_mutex_lock(philo->pf);
	num = philo->number;
	time = getime() - philo->start_time;
	printf("%zu %zu %s\n", time, num, state);
	pthread_mutex_unlock(philo->pf);
}
