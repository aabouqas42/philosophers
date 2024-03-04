/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:56:20 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/04 19:44:38 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <semaphore.h>
# include <stdio.h>
#include <sys/semaphore.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define THINKING "is thinking"
# define EATING "is eating"
# define TAKING_FORK "has taking a fork"
# define SLEAPING "is sleeping"

typedef struct s_philo
{
	size_t	start_time;
	size_t	last_meal;
	int		meal_count;
	int		number;
	int		t_2_e;
	int		t_2_d;
	int		t_2_s;
}	t_philo;

typedef struct s_data
{
	sem_t		*sem_printf;
	sem_t		*forks;
	t_philo		*philos;
	int			n_philos;
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
void	*_main(void *arg);
int		print_state(t_philo *philo, char *state);
void	_usleep(size_t ms);
int		monitor(t_data *param);

#endif