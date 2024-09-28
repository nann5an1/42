# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 21:56:14 by nsan              #+#    #+#              #
#    Updated: 2024/09/27 14:34:47 by nsan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRCS = pipex.c utils.c
# OBJS = ${SRCS:.c=.o}
# NAME = pipex.a
# LIBC = ar rcs
# CC = cc
# RM = rm -f
# CFLAGS = -Wall -Wextra -Werror
# EXEC = pipex
# .c.o:
# 	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
# ${NAME}: ${OBJS}
# 	${LIBC} ${NAME} ${OBJS}
# ${EXEC}: ${OBJS} ${NAME}
# 	${CC} ${CFLAGS} -o ${EXEC} ${OBJS} -L. -l:pipex.a
# all: ${NAME} ${EXEC}
# clean:
# 	${RM} ${OBJS}
# fclean: clean
# 	${RM} ${NAME}
# re: fclean all
# .PHONY : all clean fclean re

PROG 	= pipex
SRCS 	= pipex.c utils.c
OBJS 	= ${SRCS:.c=.o}
# NAME 	= pipex.a
HEADER	= -Iincludes
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

# Rule to compile .c files into .o files
%.o: %.c
		$(CC) ${CFLAGS} ${HEADER} -c $< -o $@

all: 		${PROG}

${PROG}:	${OBJS}
		make re -C ./libft
		$(CC) ${OBJS} -Llibft -lft -o ${PROG} 

clean:
		make clean -C ./libft
		rm -f ${OBJS}

fclean: 	clean
		make fclean -C ./libft
		rm -f ${PROG}

re:			fclean all

.PHONY: all clean fclean re
