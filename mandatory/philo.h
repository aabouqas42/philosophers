/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:10:23 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/23 16:46:13 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
#include <sys/_types/_size_t.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	lock_printf;
	pthread_t		philosopher;
	int				number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	size_t			last_meal_time;
	size_t			start_time;
} t_philos;

typedef struct s_data
{
	t_philos		*philosophers;
	pthread_mutex_t	*forks;
	int				philosphers;
} t_data;

int		_atoi(char *str);
void	*philo_start(void *arg);
int		init_data(t_data *data, char **argv);
void	init_threads(t_data *data);
size_t	getime();

#endif
