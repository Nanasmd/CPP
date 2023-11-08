# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 11:11:59 by nasamadi          #+#    #+#              #
#    Updated: 2023/11/07 17:08:04 by nasamadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern

SRC =	./main.cpp \
		./Bureaucrat.cpp \
		./AForm.cpp \
		./RobotomyRequestForm.cpp \
		./ShrubberyCreationForm.cpp \
		./PresidentialPardonForm.cpp \
		./Intern.cpp

OBJS =	./main.o \
		./Bureaucrat.o \
		./AForm.o \
		./RobotomyRequestForm.o \
		./ShrubberyCreationForm.o \
		./PresidentialPardonForm.o \
		./Intern.o

CC	= c++

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -std=c++98

$(NAME):	$(OBJS)
			@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $@"
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# $(OBJS):	$(SRC)
# 			@$(CC) $(CFLAGS) -c $(SRC)
# 			@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $@"

%.o:		%.cpp
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $@"

all:		$(NAME)

clean:
			@$(RM) $(OBJS)
			@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving objects\033[0m"

fclean:		clean
			@$(RM) $(NAME) ./North_Pole_shrubbery
			@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving $(NAME)\033[0m"

re:			fclean all

PHONY:		all clean fclean re
