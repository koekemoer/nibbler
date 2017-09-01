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

    this->_maxW = maxW;
    this->_maxH = maxH;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL init() failed" << std::endl;
        return;
    }
    this->_window = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (maxW + 2) * 16.0f, (maxH + 2) * 16.0f, SDL_WINDOW_SHOWN);
    //usleep(5000);
    if (this->_window == NULL)
    {
        std::cout << "SDL CreateWindow() failed" << std::endl;
        return;
    }
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
    std::cout << this->_maxW << std::endl;
    std::cout << this->_maxH << std::endl;
    if (this->_renderer == NULL)
    {
        std::cout << "SDL CreateRenderer() failed" << std::endl;
        return;
    }

    SDL_RenderSetLogicalSize(this->_renderer, (this->_maxW + 2) * 16.0f, (this->_maxH + 2) * 16.0f);
    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
}

void    sdl2::render()
{
    SDL_SetRenderDrawColor(this->_renderer, 100, 102, 200, 255);
    SDL_RenderClear(this->_renderer);
    SDL_Rect rect;
    //SDL_Rect sco;

    for (int y = 0; y < _maxH; y++)
    {
        for (int x = 0; x < _maxW; x++)
        {
            SDL_SetRenderDrawColor(this->_renderer, 100, 102, 200, 255);

            rect.x = x * 20.0f;
            rect.y = y * 20.0f /*-3*/;
            rect.w = 20.0f;
            rect.h = 20.0f;

            SDL_RenderFillRect(this->_renderer, &rect);

            SDL_RenderPresent(this->_renderer);
        }
    }

}