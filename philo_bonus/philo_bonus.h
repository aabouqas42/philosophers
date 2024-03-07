/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:56:20 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/07 19:45:02 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <semaphore.h>
# include <pthread.h>
# include <stdio.h>
#include <sys/_types/_pid_t.h>
#include <sys/semaphore.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/time.h>

# define THINKING "is thinking"
# define EATING "is eating"
# define TAKING_FORK "has taken a fork"
# define SLEAPING "is sleeping"

typedef struct s_philo 
{
	sem_t	*sem_printf;
	sem_t	*sem_forks;
	sem_t	*sem_lock;
	size_t	start_time;
	size_t	last_meal;
	pid_t	philo_pid;
	int		meal_count;
	int		id;
	int		eat_time;
	int		die_time;
	int		sleep_time;
} t_philo;

typedef struct s_data
{
	sem_t	*sem_printf;
	sem_t	*sem_forks;
	sem_t	*sem_lock;
	pid_t	*ids;
	size_t		start_time;
	t_philo	philo;
	int		n_philos;
}	t_data;

int		_atoi(char *s);
int		check_input(int argc, char **argv);
void	_puts(char *s, int fd);
void	_free(t_data *data);
size_t	getime(void);
int	data_init(t_data *data, int argc, char **argv, int id);
int		memory_init(t_data *data, char **argv);
int	create_proccess(t_data *data, int argc, char** argv);
void	forks_init(t_data *data);
void	_main(t_philo *data);
int		print_state(t_philo *philo, char *state);
void	_usleep(size_t ms);
void	*monitor(void *arg);
char	*_itoa(int number);
int		memory_init(t_data *data, char **argv);
int		taking_a_fork(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);

#endif
