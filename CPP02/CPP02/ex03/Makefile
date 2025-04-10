# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 19:03:10 by nsan              #+#    #+#              #
#    Updated: 2025/04/10 18:37:13 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG 	= bsp
SRCS 	= main.cpp Fixed.cpp Point.cpp, bsp.cpp
OBJS 	= ${SRCS:.cpp=.o}
CXX 		= c++ 
CXXFLAGS 	= -Wall -Wextra -Werror -std=c++98


all: 		${PROG}

${PROG}:	${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${PROG} 

%.o: %.c
		$(CXX) ${CXXFLAGS} -cpp $< -o $@

clean:
		rm -f ${OBJS}

fclean:
		rm -f ${PROG} ${OBJS}

re:			fclean all

.PHONY: all clean fclean re