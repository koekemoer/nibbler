#ifndef SNAKE_HPP
# define SNAKE_HPP

#include <vector>
#include <iostream>

class Snake{

public:
    Snake();
    Snake(const Snake &rhs);
    Snake &operator=(const Snake &rhs);
    ~Snake();

    const std::vector<int> &getPos() const;
    void setPos(const std::vector<int> &pos);

private:
    std::vector<int>    _pos;
    //bool                _head;
    //int                 _direction;
    //std::vector<int>    _lastP;

}