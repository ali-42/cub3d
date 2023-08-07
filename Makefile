# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ali <ali@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 14:50:00 by ali               #+#    #+#              #
#    Updated: 2022/04/05 11:11:00 by ali              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRCS = \
display/display_frame.c \
display/raycasting.c \
display/textures.c \
display/wall_hit.c \
error/error.c \
main/init.c \
main/main.c \
moves/key_handlers.c \
moves/move.c \
moves/rotate.c \
parsing/check_textures.c \
parsing/get_map.c \
parsing/stock_map.c \
parsing/stock_texture.c \
parsing/parsing.c \
utils/free.c \
utils/get_next_line.c 
INC_DIR = includes
MLX = libmlx.a
MLX_DIR = minilibx-linux
LIB = libft.a
LIBDIR = libft
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -g
RM = rm -f

all:		$(NAME)

$(LIB):
				$(MAKE) -C $(LIBDIR)

$(MLX):
				$(MAKE) -C $(MLX_DIR)

$(NAME):	$(OBJS) $(LIB) $(MLX)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBDIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm


libclean:
				$(MAKE) clean -C $(LIBDIR)
				$(MAKE) clean -C $(MLX_DIR)

libfclean:
				$(MAKE) fclean -C $(LIBDIR)

clean:			libclean
				$(RM) $(OBJS)

fclean:			clean libfclean
				$(RM) $(NAME)

re: 			fclean $(NAME)
