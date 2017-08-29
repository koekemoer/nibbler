#include "Snake.hpp"

Snake::Snake()
{

}

Snake::Snake(unsigned int x, unsigned int y)
{
    this->_x = x;
    this->_y = y;
}

Snake::~Snake()
{

}

Snake::Snake(const Snake &rhs)
{
    *this = rhs;
}

Snake &Snake::operator=(const Snake &rhs)
{
    this->_x = rhs.getX();
    this->_y = rhs.getY();

    return (*this);
}

unsigned int Snake::getX() const
{
    return _x;
}

unsigned int Snake::getY() const
{
    return _y;
}

void    Snake::setX(unsigned int x)
{
    this->_x = x;
}

void    Snake::setY(unsigned int y)
{
    this->_y = y;
}