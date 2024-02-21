/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:11:26 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/21 12:54:11 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	_atoi(char *str)
{
	int	res;

	if (*str == '-')
		return (printf("Invalid input :)\n"), -1);
	if (*str == '+')
		str++;
	res = 0;
	while (*str)
	{
		if (!is_digit(*str))
			return (printf("Invalid input :)\n"), -1);
		res = res * 10 + *str - 48;
		str++;
	}
	return (res);
}

int	input_checker(int argc, char **argv)
{
	int	i;
	
	i = 1;
	if (argc < 5 || argc >= 7)
		return (printf("Invalid input :)\n"), -1);
	while (argv[i])
	{
		if (_atoi(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
