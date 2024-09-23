# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corellan <corellan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 14:55:25 by corellan          #+#    #+#              #
#    Updated: 2023/01/24 15:02:37 by corellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol.c fractol_events.c fractol_utils.c fractol_draw.c \
fractol_utilscont.c

OUT = fractol.o fractol_events.o fractol_utils.o fractol_draw.o \
fractol_utilscont.o

SRC_B = fractol_bonus.c fractol_events_bonus.c fractol_utils_bonus.c \
fractol_draw_bonus.c fractol_init_bonus.c fractol_utilscont_bonus.c \
fractol_color_bonus.c fractol_colorcont_bonus.c

OUT_B = fractol_bonus.o fractol_events_bonus.o fractol_utils_bonus.o \
fractol_draw_bonus.o fractol_init_bonus.o fractol_utilscont_bonus.o \
fractol_color_bonus.o fractol_colorcont_bonus.o

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

MLX = -lmlx -framework OpenGL -framework AppKit

CC = cc

all: $(NAME)

$(NAME): $(OUT)
		$(MAKE) -C ./libft
		$(CC) $(FLAGS) $(OUT) $(LIBFT) $(MLX) -o $(NAME)

bonus: .bonus

.bonus: $(OUT_B)
		$(MAKE) -C ./libft
		$(CC) $(FLAGS) $(OUT_B) $(LIBFT) $(MLX) -o $(NAME)
		@touch .bonus

%.o: %.c
		$(CC) $(FLAGS) -I. -c $< -o $@

clean:
		$(MAKE) clean -C ./libft
		rm -f $(OUT) $(OUT_B)
		@rm -f .bonus

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re
