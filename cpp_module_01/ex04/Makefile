# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 19:12:24 by nasamadi          #+#    #+#              #
#    Updated: 2023/10/16 19:54:02 by nasamadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

SRC = main.cpp

OBJS = ${SRC:.cpp=.o}

DEP = 	 $(OBJS:.o=.d)

INCLUDE = -I .

CC = c++
RM = /bin/rm -f
CPPFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98 -MMD

.cpp.o:
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $@"
		${CC} ${CPPFLAGS} ${INCLUDE} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
	@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $@"
	${CC} ${CPPFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		$(RM) $(DEP)
		$(RM) $(OBJS)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving objects\033[0m"


fclean:	clean
		$(RM) $(NAME)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving $(NAME)\033[0m"


re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
