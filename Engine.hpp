#ifndef COREGAME_HPP
# define COREGAME_HPP

#include <iostream>
#include <list>

class Engine
{
private:
    int                 _winWidth;
    int                 _winHeight;
    
public:
    Engine();
    Engine(unsigned int x, unsigned int y);
    Engine(const Engine &rhs);
    Engine &operator=(const Engine &rhs);
    ~Engine();

    int     getWinWidth() const;
    int     getWinHeight() const;
    void    setWinWidth(int width);
    void    setWinHeight(int height);
    
};

#endif