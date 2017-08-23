#ifndef SFML_HPP
# define SFML_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class   SFML
{
public:
    SFML();
    SFML(unsigned int w, unsigned int h);
    ~SFML();

    void    init(unsigned int &w, unsigned int &h);
    //void    render();


private:
    sf::RenderWindow    *window;
    unsigned int        _w;
    unsigned int        _h;
}