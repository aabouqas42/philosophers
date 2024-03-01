# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 10:22:26 by aabouqas          #+#    #+#              #
#    Updated: 2024/03/01 20:04:47 by aabouqas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc 
CFLAGS = -fsanitize=thread
SRC = mandatory/philo_init.c mandatory/philo_utils.c mandatory/memory_manager.c mandatory/monitor.c mandatory/states.c
NAME = philo
MAIN = philo.c
MAIN_OBJ = philo.o
HEADER = mandatory/philo.h
OBJ = $(SRC:%.c=%.o)

all: $(NAME) $(HEADER) 

$(NAME): $(MAIN_OBJ) $(OBJ) $(HEADER) ./Makefile
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