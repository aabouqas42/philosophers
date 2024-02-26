/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:10:23 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/25 21:36:54 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*pf;
	pthread_mutex_t	*meal_time;
	pthread_t		philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			last_meal;
	size_t			start_time;
	int				number;
} t_philos;

typedef struct s_data
{
	t_philos		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	pf;
	pthread_mutex_t	meal_time_lock;
	int				number_of_philos;
} t_data;

int		_atoi(char *str);
void	*philo_start(void *arg);
int		init_data(t_data *data, char **argv);
void	init_threads(t_data *data);
size_t	getime();
void	ph_do(t_philos *philo, char *state);
int		input_checker(int argc, char **argv);

#endif
