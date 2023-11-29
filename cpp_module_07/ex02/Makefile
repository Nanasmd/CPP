# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 15:39:43 by nasamadi          #+#    #+#              #
#    Updated: 2023/11/07 17:13:44 by nasamadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array

SRC = main.cpp

OBJS = ${SRC:.cpp=.o}

INCLUDE = -I .

CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
		@${CC} ${CPPFLAGS} ${INCLUDE} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
		@${CC} ${CPPFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $@"

all:	${NAME}

clean:
		@${RM} ${OBJS}
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving objects\033[0m"

fclean:	clean
		@${RM} ${NAME}
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving $(NAME)\033[0m"

re: clean all

.PHONY: all clean re