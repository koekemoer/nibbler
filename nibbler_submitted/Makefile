# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmather <dmather@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/23 08:55:42 by dmather           #+#    #+#              #
#    Updated: 2017/06/24 23:00:21 by dmather          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= nibbler
LIB1		= libft_1.so
LIB2		= libft_2.so
LIB3		= libft_3.so
NC			= \033[0m
CR			= \033[31m
CB			= \033[34m
CP			= \033[38;5;128m
CY			= \033[33m
FLAGS		= -Wall -Wextra -Werror
DYNAM		= -shared -fPIC
DEP         = -Wno-deprecated -framework OpenGL -framework GLUT

INCLUDES	=	-I includes
SRCS		=	src/main.cpp	\
				src/Game.cpp

SRCSLIB1	= lib1/NibblerDefault.cpp
INCLLIB1	= -I lib1/

SRCSLIB2	= lib2/gl_two.cpp
INCLLIB2	= -I lib2/

SRCSLIB3	= lib3/gl_three.cpp
INCLLIB3	= -I lib3/

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

all: $(NAME)

$(NAME):
	@g++ $(FLAGS) $(DEP) $(DYNAM) $(INCLLIB1) $(SRCSLIB1) -o $(LIB1)
	@g++ $(FLAGS) $(DEP) $(DYNAM) $(INCLLIB2) $(SRCSLIB2) -o $(LIB2)
	@g++ $(FLAGS) $(DEP) $(DYNAM) $(INCLLIB3) $(SRCSLIB3) -o $(LIB3)
	@g++ $(SRCS) $(FLAGS) $(INCLLIB1) $(INCLUDES) $(DEP) -L . -lft_2 -L . -lft_2 -L . -lft_3 -o $(NAME)
	@echo "$(CR)Terminal Broken!$(NC)"
	@sleep 2
	@echo "Just Kidding ;)"
	@sleep 1
	@echo "$(CB)$(NAME) ==> Made '$(NAME)'$(NC)"

clean:
	@rm -f $(NAME)
	@echo "$(CR)$(NAME) ==> Removed '$(NAME)'$(NC)"

fclean: clean
	@rm -f $(LIB1) $(LIB2) $(LIB3)
	@echo "$(CR)$(NAME) ==> Removed all Dynamic Libraries$(NC)"

re: fclean all

del:
	@rm -f $(NAME)
	@echo "$(CR)$(NAME) ==> Removed '$(NAME)'$(NC)"

run: del all
