# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 10:22:26 by aabouqas          #+#    #+#              #
#    Updated: 2024/03/10 10:36:54 by aabouqas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wextra -Werror -Wall
SRC = philo_bonus.c data_init_bonus.c philo_utils_bonus.c memory_manager_bonus.c monitor_bonus.c actions_bonus.c
NAME = philo_bonus
HEADER = philo_bonus.h
OBJ = $(SRC:%.c=%.o)

all: $(NAME) $(HEADER) 

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(MAIN_OBJ)

.PHONY: clean 