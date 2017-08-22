#include "Snake.hpp"

Snake::Snake()
{

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
    this->_pos = rhs.getPos();
}

const std::vector<int> &Snake::getPos() const
{
    return _pos;
}

void    Snake::setPos(const std::vector<int> &pos)
{
    this->_pos = pos;
}