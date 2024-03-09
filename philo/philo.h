/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:19 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/09 19:41:08 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define THINKING "is thinking"
# define EATING "is eating"
# define TAKING_FORK "has taken a fork"
# define SLEAPING "is sleeping"

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*printf;
	pthread_mutex_t	lock;
	pthread_t		philo;
	size_t			start;
	size_t			last_meal;
	int				meal_count;
	int				id;
	int				eat_time;
	int				die_time;
	int				sleep_time;
	int				*died;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_mutex_t	printf;
	int				numof_philos;
	int				died;
}	t_data;

int		_atoi(char *s);
int		check_input(int argc, char **argv);
void	_puts(char *s, int fd);
void	_free(t_data *data);
size_t	getime(void);
void	data_init(t_data *data, int argc, char **argv);
int		memory_init(t_data *data, char **argv);
int		create_threads(t_data *data);
void	forks_init(t_data *data);
void	*_main(void *arg);
int		print_state(t_philo *philo, char *state);
void	_usleep(size_t ms, t_philo *philo);
int		monitor(t_data *param);
int		mutex_init(t_data *data);
int		taking_a_fork(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);

#endif
