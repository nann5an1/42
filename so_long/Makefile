# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 20:04:35 by nsan              #+#    #+#              #
#    Updated: 2024/10/27 19:26:15 by nsan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG    =   so_long
SRCS    =   so_long.c utils1.c utils2.c validate.c flood_fill.c free_map_utils1.c free_map_utils2.c mlx_main.c mlx_utils.c
OBJS    =   ${SRCS:.c=.o}
CC      =   cc
CFLAGS  =   -Wall -Werror -Wextra -g
HEADER  =   -I./include

MLX_DIR =   ./minilibx-linux
LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf

MLX_PATH = ${MLX_DIR}/libmlx.a
LIBFT_PATH = ${LIBFT_DIR}/libft.a
FT_PRINTF_PATH = ${FT_PRINTF_DIR}/libftprintf.a
MLX_FLAGS = -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)

all:    ${PROG}

${PROG}: ${OBJS}
		make -C ${FT_PRINTF_DIR}
		make -C ${LIBFT_DIR}
		make -C ${MLX_DIR}
		${CC} ${OBJS} -L${LIBFT_DIR} -lft -L${FT_PRINTF_DIR} -lftprintf ${MLX_FLAGS} -o ${PROG}

%.o: %.c
		$(CC) ${CFLAGS} ${HEADER} -c $< -o $@

clean:
		make clean -C ${FT_PRINTF_DIR}
		make clean -C ${LIBFT_DIR}
		make clean -C ${MLX_DIR}
		rm -f ${OBJS}

fclean: clean
		make fclean -C ${FT_PRINTF_DIR}
		make fclean -C ${LIBFT_DIR}
		make clean -C ${MLX_DIR}
		rm -f ${PROG}

re: fclean all

.PHONY: all clean fclean re
