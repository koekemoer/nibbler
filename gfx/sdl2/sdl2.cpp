#include "sdl2.hpp"

/*extern "C" Basegfx *create()
{

}*/

sdl2::sdl2()
{
    this->_maxW = 0;
    this->_maxH = 0;

    this->_window = NULL;
    this->_renderer = NULL;   
}

sdl2::sdl2(unsigned int w, unsigned int h)
{
    this->_maxW = w;
    this->_maxH = h;
}

sdl2::sdl2(const sdl2 &rhs)
{
    *this = rhs;
}

sdl2::~sdl2()
{
    SDL_DestroyRenderer(this->_renderer);
    this->_renderer = NULL;

    SDL_DestroyWindow(this->_window);
    this->_window = NULL;

    SDL_Quit();
}

sdl2 &sdl2::operator=(const sdl2 &rhs)
{
    this->_maxW = rhs.getW();
    this->_maxH = rhs.getH();
}

int sdl2::getW()
{
    return this->_maxW;
}

int sdl2::getH()
{
    return this->_maxH;
}

void    sdl2::init(unsigned int w, unsigned int h)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL init() failed" << std::endl;
        return;
    }
    this->window = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (_maxX) * 20.0f, (_maxY) * 20.0f, SDL_WINDOW_SHOWN);
    if (this->_window == NULL)
    {
        std::cout << "SDL CreateWindow() failed" << std::endl;
        return;
    }
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
    if (this->_renderer == NULL)
    {
        std::cout << "SDL CreateRenderer() failed" << std::endl;
        return;
    }
}