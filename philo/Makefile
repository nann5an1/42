# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 14:17:10 by marvin            #+#    #+#              #
#    Updated: 2024/11/28 14:17:10 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG 	= philo
SRCS 	= action.c initialize.c monitor.c utils.c philo.c threads.c
OBJS 	= ${SRCS:.c=.o}
HEADER	= -Iincludes
CC 		= cc 
CFLAGS 	= -Wall -Wextra -Werror 
#-g -fsanitize=thread 
#LIB = -lpthread

all: 		${PROG}

${PROG}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${HEADER} -o ${PROG} 
#${LIB}

%.o: %.c
		$(CC) ${CFLAGS} ${HEADER} -c $< -o $@

clean:
		rm -f ${OBJS}

fclean:
		rm -f ${PROG} ${OBJS}

re:			fclean all

.PHONY: all clean fclean re