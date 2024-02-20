/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:10:23 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/20 23:46:40 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>

typedef enum philo_state_e
{
	EATING,
	SLEEPING,
	DIED,
} philo_stat_t;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_philos
{
	philo_stat_t	philo_state;
	pthread_t		thread;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int				philo_id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				someone_dead;
} t_philos;

typedef struct s_data
{
	t_philos	*philos;
	t_fork		*forks;
	int			philosphers;
} t_data;

#endif
