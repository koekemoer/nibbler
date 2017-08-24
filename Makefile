NAME = nibbler

CC = clang++

CFLAGS = -Wall -Werror -Wextra -std=c++11

SRC = Snake.cpp Engine.cpp main.cpp

OBJ = $(SRC:*.cpp=%.o)

$(NAME):
	make -C ./gfx/sdl2/
	@$(CC) $(CFLAGS) -Qunused-arguments -o $(NAME) $(OBJ) -ldl

all: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re:
	fclean all