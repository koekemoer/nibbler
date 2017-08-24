#ifndef SNAKE_HPP
# define SNAKE_HPP

#include <vector>
#include <iostream>

class Snake{

public:
    Snake();
    Snake(unsigned int x, unsigned int y);
    Snake(const Snake &rhs);
    Snake &operator=(const Snake &rhs);
    ~Snake();

    unsigned int getX() const;
    unsigned int getY() const;
    void setX(unsigned int x);
    void setY(unsigned int y);

private:
    unsigned int    _x;
    unsigned int    _y;
    //bool                _head;
    //int                 _direction;
    //std::vector<int>    _lastP;

};

#endif