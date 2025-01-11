# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 16:37:59 by nsan              #+#    #+#              #
#    Updated: 2024/12/22 12:59:37 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG 	= minishell
SRCS 	= main.c str_utils.c utils_1.c builtin_utils.c libft/ft_strdup.c libft/ft_strncmp.c libft/ft_split.c
OBJS 	= ${SRCS:.c=.o}
HEADER	= -Iincludes -lreadline 
CC 		= cc
CFLAGS 	= #-Wall -Wextra -Werror

all: 		${PROG}

${PROG}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${HEADER} -o ${PROG}

%.o: %.c
		$(CC) ${CFLAGS} ${HEADER} -c $< -o $@

clean:
		rm -f ${OBJS}

fclean:
		rm -f ${PROG} ${OBJS}

re:			fclean all

.PHONY: all clean fclean re