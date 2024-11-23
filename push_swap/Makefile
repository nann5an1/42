# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 13:46:29 by nsan              #+#    #+#              #
#    Updated: 2024/10/17 20:46:19 by nsan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG 	= push_swap
SRCS 	= push_swap.c list_utils.c radix.c rules.c sort.c utils_ext.c utils.c utils_add.c input_error.c
OBJS 	= ${SRCS:.c=.o}
HEADER	= -Iincludes
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

%.o: %.c
		$(CC) ${CFLAGS} ${HEADER} -c $< -o $@

all: 		${PROG}

${PROG}:	${OBJS}
		make bonus -C ./libft
		$(CC) ${OBJS} -Llibft -lft -o ${PROG} 

clean:
		make clean -C ./libft
		make clean -C ./libft bonus
		rm -f ${OBJS}

fclean: 	clean
		make fclean -C ./libft
		rm -f ${PROG}

re:			fclean all

.PHONY: all clean fclean re