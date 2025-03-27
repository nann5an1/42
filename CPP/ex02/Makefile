# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 19:32:52 by nsan              #+#    #+#              #
#    Updated: 2025/03/27 13:55:26 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG 	= Account
SRCS 	= tests.cpp Account.cpp
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
