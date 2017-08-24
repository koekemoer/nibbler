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
		$(CC) -fPIC -shared $(SDL_CFLAGS) $(CFLAGS) sdl2.cpp -o sdl2.so
		$(CC) -shared -Wl -soname sdl2.so -o sdl2.so *.o


#On Mac OS X, compile with:
#all:
#	g++ -dynamiclib -flat_namespace myclass.cpp -o myclass.so
#	g++ class_user.cpp -o class_user

#On Linux, compile with:

#g++ -fPIC -shared myclass.cc -o myclass.so
#g++ class_user.cc -ldl -o class_user

##$(CC) -fPIC $(SRC) $(CFLAGS) $(SDL_CFLAGS) -o $(NAME)
