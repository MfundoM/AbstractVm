# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/02 11:04:11 by mmthethw          #+#    #+#              #
#    Updated: 2018/07/02 11:04:13 by mmthethw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

CC = g++ -Wall -Wextra -Werror

FILES = main.cpp  \
					 AbstractFactory.class.cpp \
					 Exception.class.cpp \
					 ExecuteVM.class.cpp \
					 Instructions.class.cpp \
					 StackVM.class.cpp
SRC := $(addprefix srcs/, $(FILES))

OBJ = $(SRC:.cpp=.o)

INC = -I includes/

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(INC) -o $(NAME) $(OBJ)
	@echo "\033[33m\033[33m$(NAME) was compiled successfully\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[33m\033[33m.o files removed successfully\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[33m\033[33m$(NAME) was removed successfully\033[0m"

re: fclean all

.PHONY: clean fclean re
