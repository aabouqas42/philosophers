# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 11:10:35 by aabouqas          #+#    #+#              #
#    Updated: 2024/02/21 12:57:25 by aabouqas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = 
SRC = mandatory/philo.c mandatory/philo_initializer.c mandatory/philo_utils.c
NAME = philo
HEADER = mandatory/philo.h
OBJ = $(SRC:%.c=%.o)

all: $(NAME) $(HEADER)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

mandatory/$(OBJ): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)