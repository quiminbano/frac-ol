# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corellan <corellan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 14:55:25 by corellan          #+#    #+#              #
#    Updated: 2023/01/11 15:11:39 by corellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c fractol_events.c fractol_utils.c

OUT = main.o fractol_events.o fractol_utils.o

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

MLX = -lmlx -framework OpenGL -framework AppKit

CC = cc

all: $(NAME)

$(NAME): $(OUT)
		$(MAKE) -C ./libft
		$(CC) $(FLAGS) -I. -c $(SRC)
		$(CC) $(FLAGS) $(OUT) $(LIBFT) $(MLX) -o $(NAME)

clean:
		$(MAKE) clean -C ./libft
		rm -f $(OUT)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re