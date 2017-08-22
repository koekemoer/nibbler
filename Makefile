NAME = nibbler

CC = clang++

CFLAGS = -Wall -Werror -Wextra -std=c++11

SRC = src/*.cpp

OBJ = $(SRC:*.cpp=%.o)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re:
	fclean all