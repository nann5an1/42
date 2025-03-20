# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 15:59:41 by marvin            #+#    #+#              #
#    Updated: 2025/03/20 15:59:41 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = megaphone.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = megaphone
LIBC = ar rcs
CPP = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
	${CPP} ${CFLAGS} -c $< -o ${<:.cpp=.o}
${NAME}: ${OBJS}
	${C} ${CFLAGS} -o ${NAME} ${OBJS}
all: ${NAME}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY : all clean fclean re
