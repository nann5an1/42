# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 16:57:04 by nsan              #+#    #+#              #
#    Updated: 2025/03/26 16:57:04 by nsan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG 	= PhoneBook
SRCS 	= PhoneBook.cpp Contact.cpp Main.cpp
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
