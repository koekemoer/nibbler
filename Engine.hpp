#ifndef COREGAME_HPP
# define COREGAME_HPP

#include <iostream>
#include <list>
#include <time.h>
#include <dlfcn.h>
#include <unistd.h>

#include "Basegfx.hpp"
#include "Snake.hpp"

//#define SMFLLIB "../dynamicLibraries/SFML/SFMLlib.so"

class Engine
{
private:
    unsigned int        _winWidth;
    unsigned int        _winHeight;
    //std::vector<Snake*> snake;
    //unsigned int        _score;
    void                *handle;
    Basegfx             *lib;
    
public:
    Engine();
    Engine(unsigned int w, unsigned int h);
    Engine(const Engine &rhs);
    Engine &operator=(const Engine &rhs);
    ~Engine();

    int     getWinWidth() const;
    int     getWinHeight() const;
    void    setWinWidth(int width);
    void    setWinHeight(int height);
    
    void    init(unsigned int w, unsigned int h);
    void    loadLib(int gui);
    void    gameLoop();
    
};

#endif