# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 10:22:26 by aabouqas          #+#    #+#              #
#    Updated: 2024/03/07 17:54:01 by aabouqas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc 
CFLAGS = -Wextra -Werror -Wall -g
SRC = philo.c data_init.c philo_utils.c memory_manager.c monitor.c actions.c
NAME = philo
HEADER = philo.h
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
	rm -rf $(OBJ)
	rm -rf $(MAIN_OBJ)

.PHONY: clean