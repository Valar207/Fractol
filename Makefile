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

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m

NAME = fractol

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIB_PATH = ./src/libft/

LIB = ./src/libft/libft.a

MLX_PATH = ./minilibx/

SRCS =  src/main.c \
		src/events.c \
		src/events2.c \
		src/fill_pix.c \
		src/init_var.c \
		src/mandelbrot.c \
		src/mandelbar.c \
		src/burning_ship.c \
		src/celtic_mandelbrot.c \
		src/julia.c \
		src/mouse_events.c \
		src/color.c

OBJ = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB) -L $(MLX_PATH) $(MLX_FLAGS)
	@echo "$(YELLOW)./$(NAME) $(GREEN)ready   ✅ "

-include $(DEPS)

./%.o : ./%.c makefile
	@gcc $(FLAGS) -I $(LIB_PATH) -MMD -MP -c $< -o $@

$(LIB) : force
	@make -C $(LIB_PATH)

force :

clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW).o    $(RED)deleted 💯 "
	@rm -f $(DEPS)
	@echo "$(YELLOW).d    $(RED)deleted 💯 "
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(YELLOW)./$(NAME) $(RED)deleted 💯 "

re: fclean all

.SILENT:

.PHONY: all clean fclean re force