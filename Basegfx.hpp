#ifndef BASEGFX_HPP
# define BASEGFX_HPP

#include <iostream>
#include "Engine.hpp"

class Basegfx
{
private:
    unsigned int     _screenW;
    unsigned int     _screenH;
    Engine  *engine;

public:
    Basegfx(engine *ref);
    virtual ~Basegfx();

    void    draw();
    void    update();

    unsigned int    getScreenW();
    unsigned int    getScreenH();
    void            setScreenW(unsigned int w);
    void            setScreenH(unsigned int h);
    Engine          *getEngine() const;
    void            setEngine(Engine *engine);
    void            checkInput();
    void            exit();

}