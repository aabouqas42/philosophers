/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:25 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/27 12:43:58 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->pf);
	free (data->forks);
	free (data->philos);
}

int	memory_init(t_data *data, char **argv)
{
	int		pf_failed;
	int		mt_failed;
	int		i;

	data->number_of_philos = _atoi(argv[1]);
	data->philos = malloc (sizeof(t_philo) * data->number_of_philos);
	if (data->philos == NULL)
		return (_puts("Unexpected Error\n", 2), -1);
	data->forks = malloc (sizeof(pthread_mutex_t) * data->number_of_philos);
	if (data->forks == NULL)
		return (_free(data), _puts("Unexpected Error\n", 2), -1);
	pf_failed = pthread_mutex_init(&data->pf, NULL);
	if (pf_failed)
		return (_free(data), _puts("Unexpected Error\n", 2), -1);
	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (_free(data), _puts("Unexpected Error\n", 2), -1);
		if (pthread_mutex_init(&data->philos[i].meal_lock, NULL) != 0)
			return (_free(data), _puts("Unexpected Error\n", 2), -1);
		i++;
	}
	return (0);
}
