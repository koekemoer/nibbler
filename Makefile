NAME = nibbler

CC = clang++

CFLAGS = -Wall -Werror -Wextra -std=c++11

SRC = Snake.cpp Engine.cpp main.cpp Basegfx.cpp

OBJ = $(SRC:*.cpp=%.o)

$(NAME):
	#make -C ./gfx/sdl2/
	$(CC) $(CFLAGS) -shared -fPIC -lSDL2 -lGL -I gfx/sdl2/ gfx/sdl2/sdl2.cpp -o lib1.so
	$(CC) $(CFLAGS)  $(SRC) -I gfx/sdl2/ -lSDL2 -lGL -L . -l1 -o $(NAME)

all: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re:
	fclean all