# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrossi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 18:31:54 by vrossi            #+#    #+#              #
#    Updated: 2019/09/18 10:55:57 by vrossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
HEADERS = libft.h
FLAGS =  -Wall -Wextra -Werror
FILES = src/main.c \
		src/events.c \
		src/fill_pix.c \
		src/init_var.c \
		src/mandelbrot.c \
		src/mandelbar.c \
		src/burning_ship.c \
		src/celtic_mandelbrot.c \
		src/julia.c \
		src/mouse_events.c \
		src/color.c
LIB = ./src/libft/libft.a

OBJ =	$(FILES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) -I /usr/local/include $(FILES) -L /usr/local/lib -lmlx $(LIB) -framework openGL -framework AppKit

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re