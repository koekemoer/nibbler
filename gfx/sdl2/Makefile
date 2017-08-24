CC = clang++

NAME = sdl2lib.so

CFLAGS = -Wall -Werror -Wextra -std=c++11

SDL_LIBS = -lSDL2 -lGL

SRC = ../../Basegfx.cpp sdl2.cpp

OBJ = ../../Basegfx.o sdl2.o

all: $(OBJS)
		$(CC) $(SRC) $(CFLAGS) -c -fPIC $(SDL_LIBS)
		$(CC) $(OBJ) -fPIC -undefined dynamic_lookup -shared -o $(NAME) $(SDL_LIBS)




