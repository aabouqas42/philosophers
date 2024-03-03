/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:17 by aabouqas          #+#    #+#             */
/*   Updated: 2024/03/03 10:59:52 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	_puts(char *s, int fd)
{
	if (s && *s)
	{
		write (fd, s, 1);
		_puts(s + 1, fd);
	}
}

int	_atoi(char *s)
{
	int	number;

	if (s == NULL)
		return (-1);
	if (*s == 0 || *s == '-')
		return (-1);
	if (*s == '+')
		s++;
	number = 0;
	while (*s >= '0' && *s <= '9')
		number = number * 10 + *s++ - 48;
	if (number == 0)
		return (-1);
	return (number);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 6)
		if (_atoi(argv[5]) == -1)
			return (_puts("Input Error\n", 2), -1);
	if (argc < 5 || argc > 6)
		return (_puts("Input Error\n", 2), -1);
	while (argv[i])
		if (_atoi(argv[i++]) == -1)
			return (_puts("Input Error\n", 2), -1);
	return (0);
}

size_t	getime(void)
{
	struct timeval	_timeval;

	gettimeofday(&_timeval, NULL);
	return (_timeval.tv_sec * 1000 + _timeval.tv_usec / 1000);
}

void	_usleep(size_t ms)
{
	size_t	tosleep;

	tosleep = getime();
	while (getime() - tosleep < ms)
		usleep(500);
}
