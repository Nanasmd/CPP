# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 14:17:43 by nasamadi          #+#    #+#              #
#    Updated: 2023/10/16 19:54:24 by nasamadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### VARS ###

UNAME_S := $(shell uname -s)

### PROGRAM ###
NAME		= phonebook

### SOURCES ###
SRC_DIR		= sources/
OBJ_DIR		= .objs/
INCLUDES	= includes/

SRC		=	$(SRC_DIR)ClassPhonebook.cpp \
			$(SRC_DIR)ClassContacts.cpp \
			$(SRC_DIR)main.cpp \
			$(SRC_DIR)add.cpp \
			$(SRC_DIR)search.cpp
			

OBJ	= $(SRC:$(SRC_DIR)%=$(OBJ_DIR)%.o)
DEP = 	 $(OBJ:.o=.d)

### COMPILER ###
CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -MMD
RM			= /bin/rm -rf

### RULES ###
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

PHONY += sanitize
ifeq ($(UNAME_S),Linux)
sanitize: CXXFLAGS += -pedantic -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null
endif
ifeq ($(UNAME_S),Darwin)
sanitize: CXXFLAGS += -pedantic -g3 -fsanitize=address
endif
sanitize: $(NAME)

PHONY += thread
thread: CXXFLAGS += -g3 -fsanitize=thread
thread: $(NAME)

clean:
	@$(RM) $(OBJ_DIR)
	rm -rf $(DEP)
	@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving objects\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving $(NAME)\033[0m"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
