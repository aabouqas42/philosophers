# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 11:10:35 by aabouqas          #+#    #+#              #
#    Updated: 2024/02/21 13:54:06 by aabouqas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -fsanitize=address
SRC = mandatory/philo_initializer.c mandatory/philo_utils.c
NAME = philo
MAIN = philo.c
MAIN_OBJ = philo.o
HEADER = mandatory/philo.h
OBJ = $(SRC:%.c=%.o)

all: $(NAME) $(HEADER)

$(NAME): $(MAIN_OBJ) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJ) -o $(NAME)

$(MAIN_OBJ): $(MAIN) $(HEADER)
	$(CC) $(CFLAGS) -c $(MAIN) -o $(MAIN_OBJ)

mandatory/%.o: mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(MAIN_OBJ)

.PHONY: clean