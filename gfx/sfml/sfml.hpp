#ifndef SFML_HPP
# define SFML_HPP

#include <SFML/Graphics.hpp>
//#include <vector>
#include "../../Basegfx.hpp"

class sfml : public Basegfx
{
private:
    int        _maxW;
    int        _maxH;

    sf::RenderWindow    *_window;

public:
    sfml();
    sfml(unsigned int w, unsigned int h);
    sfml(sfml const &rhs);
    ~sfml();
    sfml &operator=(sfml const &rhs);

    void init(unsigned int &maxW, unsigned int &maxH);

    int getW() const;
    int getH() const;
    //void    render();
};

#endif