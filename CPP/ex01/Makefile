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

PROG 	= PhoneBook
SRCS 	= PhoneBook.cpp Contact.cpp Main.cpp
OBJS 	= ${SRCS:.cpp=.o}
HEADER	= -Iincludes
CPP 		= c++ 
CFLAGS 	= -Wall -Wextra -Werror -std=c++98


all: 		${PROG}

${PROG}:	${OBJS}
		${CPP} ${CFLAGS} ${OBJS} ${HEADER} -o ${PROG} 

%.o: %.c
		$(CPP) ${CFLAGS} ${HEADER} -cpp $< -o $@

clean:
		rm -f ${OBJS}

fclean:
		rm -f ${PROG} ${OBJS}

re:			fclean all

.PHONY: all clean fclean re
