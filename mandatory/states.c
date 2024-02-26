/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:58:30 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/25 22:18:16 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_do(t_philos *philo, char *state)
{
	size_t	num;
	size_t	time;
	
	num = philo->number;
	time = getime() - philo->start_time;
	pthread_mutex_lock(philo->pf);
	printf("%zu %zu %s\n", time, num, state);
	pthread_mutex_unlock(philo->pf);
}
