#include "Engine.hpp"

Engine::Engine()
{

}

Engine::~Engine()
{

}

Engine::Engine(unsigned int w, unsigned int h)
{
    this->_winWidth = w;
    this->_winHeight = h;
}

Engine::Engine(const Engine &rhs)
{
    *this = rhs;
}

Engine &Engine:: operator=(const Engine &rhs)
{
    this->_winWidth = rhs.getWinWidth();
    this->_winHeight = rhs.getWinHeight();
    return (*this);
}

void    Engine::getWinWidth() const
{
    return this->_winWidth;
}

void    Engine::getWinHeight() const
{
    return this->_winHeight;
}

int     Engine::setWinWidth(int width)
{
    this->_winWidth = width;
}

int     Engine::setWinHeight(int height)
{
    this->_winHeight = height;
}