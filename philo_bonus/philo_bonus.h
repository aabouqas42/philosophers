/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:56:20 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/05 13:59:18 by aabouqas         ###   ########.fr       */
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
# define TAKING_FORK "has taking a fork"
# define SLEAPING "is sleeping"

typedef struct s_data
{
	sem_t	*sem_printf;
	sem_t	*sem_forks;
	size_t	start_time;
	size_t	last_meal;
	int		meal_count;
	int		number;
	int		t_2_e;
	int		t_2_d;
	int		t_2_s;
	int		philo_pid;
	int		n_philos;
	pid_t	ppid;
}	t_data;

int		_atoi(char *s);
int		check_input(int argc, char **argv);
void	_puts(char *s, int fd);
void	_free(t_data *data);
size_t	getime(void);
int		data_init(t_data *data, int argc, char **argv);
int		memory_init(t_data *data, char **argv);
int		create_proccess(t_data *data);
void	forks_init(t_data *data);
void	_main(t_data *data);
int		print_state(t_data *philo, char *state);
void	_usleep(size_t ms);
void	*monitor(void *arg);

#endif
