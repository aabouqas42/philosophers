# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 10:22:26 by aabouqas          #+#    #+#              #
#    Updated: 2024/03/04 22:04:53 by aabouqas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc 
CFLAGS = 
SRC = philo_bonus.c data_init.c philo_utils.c memory_manager.c monitor.c
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
	rm -rf $(OBJ)
	rm -rf $(MAIN_OBJ)

.PHONY: clean