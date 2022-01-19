# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 16:47:42 by bepifani          #+#    #+#              #
#    Updated: 2022/01/18 16:59:30 by bepifani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c

SRC_FILES = make_massiv.c	maxsort.c	push_swap.c	push.c\
			reverse_rotate.c	rotate.c	sort.c	swap.c\
			utils.c		score.c		maxsort_utils.c

OBJECTS = $(SRC_FILES:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ 
	
clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re