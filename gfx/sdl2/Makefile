CC = clang++

NAME = sdl2lib.so

CFLAGS = -Wall -Werror -Wextra -std=c++11

#SDL_LIBS = -lSDL2 -lGL
SDL_LIBS = $(shell sdl2-config --libs)
SDL_CFLAGS = $(shell sdl2-config --cflags)

SRC = ../../Basegfx.cpp sdl2.cpp

#OBJ = ../../Basegfx.o sdl2.o
OBJ = $(SRC:.cpp=.o)

all: $(OBJS)
		$(CC) -fPIC $(SRC) $(CFLAGS) $(SDL_CFLAGS) -o $(NAME)
		
#$(CC) $(OBJ) -fPIC -undefined dynamic_lookup -shared -o $(NAME) $(SDL_LIBS)

#all: 
	#$(CC) -fPIC -shared $(SRC) -o libsdl2.so
	#$(CC) 

#g++ -fPIC -shared myclass.cc -o myclass.so
#g++ class_user.cc -ldl -o class_user

