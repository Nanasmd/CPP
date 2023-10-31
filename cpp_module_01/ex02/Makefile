# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 19:10:01 by nasamadi          #+#    #+#              #
#    Updated: 2023/10/16 19:53:53 by nasamadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= brain
SRC_DIR		= ./
OBJ_DIR		= .objs/
INCLUDES	= ./

SRC		=	$(SRC_DIR)main.cpp

OBJ	= $(SRC:$(SRC_DIR)%=$(OBJ_DIR)%.o)
DEP = 	 $(OBJ:.o=.d)

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -MMD
RM			= /bin/rm -rf

all: $(NAME)

$(OBJ_DIR):
	@mkdir $@

$(OBJ): | $(OBJ_DIR)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%
	@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $@"
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $@"
	@$(CC) -o $@ $^

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(DEP)
	@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving objects\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving $(NAME)\033[0m"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
