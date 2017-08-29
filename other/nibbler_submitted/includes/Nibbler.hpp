#ifndef NIBBLER_HPP
# define NIBBLER_HPP

# include <OpenGL/gl.h>
# include <GLUT/glut.h>
# include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
# include "Game.hpp"
#include <dlfcn.h>

# define WINDOW_HEIGHT 500
# define WINDOW_WIDTH 500
# define COLOUMNS 50
# define ROWS 50
# define DEFAULT_FPS 10
# define DEFAULT_SNAKE_LEN 4
# define UP 1
# define DOWN -1
# define RIGHT 2
# define LEFT -2
# define MAX 200

char	*con(const char * first, const char * second);
void	display_callback();
void	keyboard_callback(int key, int, int);
void	timer_callback(int);
void	reshape_callback(int w, int h);
void	close(void);
int		main(int argc, char **argv);

#endif