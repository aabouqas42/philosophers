/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:10:23 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/24 18:42:37 by aabouqas         ###   ########.fr       */
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
	pthread_t		philosopher;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			last_meal_time;
	int				number;
	size_t			start_time;
} t_philos;

typedef struct s_data
{
	t_philos		*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	pf;
	int				philosphers;
} t_data;

int		_atoi(char *str);
void	*philo_start(void *arg);
int		init_data(t_data *data, char **argv);
void	init_threads(t_data *data);
size_t	getime();
void	ph_do(t_philos *philo, char *state);
int		input_checker(int argc, char **argv);

#endif
