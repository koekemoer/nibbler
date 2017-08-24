#ifndef SDL2_HPP
# define SDL2_HPP

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <iostream>
#include <sstream>
#include "Basegfx.hpp"

class sdl2 : public Basegfx
{
private:
    int     maxW;
    int     maxH
    int     rand;

    SDL_Window      *_window;
    SDL_Renderer    *_renderer;
    SDL_Event       _event; // key input

public:
    sdl2();
    sdl2(unsigned int w, unsigned h);
    sdl2(const sdl2 &rhs);
    ~sdl2();
    sdl2 &operator=(const sdl2 &rhs);

    void init(unsigned int w, unsigned int h);

    int getW();
    int getH();
    
};

#endif