#include "sdl2.hpp"

/*extern "C" Basegfx *create()
{

}*/

extern "C" Basegfx *create()
{
    return new sdl2;
}

extern "C" void destroy(Basegfx *obj)
{
    delete obj;
}

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

sdl2::sdl2(sdl2 const &rhs)
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

sdl2 &sdl2::operator=(sdl2 const &rhs)
{
    this->_maxW = rhs.getW();
    this->_maxH = rhs.getH();

    return (*this);
}

int sdl2::getW() const
{
    return this->_maxW;
}

int sdl2::getH() const
{
    return this->_maxH;
}

void    sdl2::init(unsigned int &maxW, unsigned int &maxH)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL init() failed" << std::endl;
        return;
    }
    this->_window = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (maxW + 2) * 20.0f, (maxH + 2) * 20.0f, SDL_WINDOW_SHOWN);
    //usleep(5000);
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

void    sdl2::render(char **map)
{
    
}