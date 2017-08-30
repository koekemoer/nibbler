#include "sfml.hpp"

extern "C" Basegfx *create()
{
    return new sfml;
}

extern "C" void destroy(Basegfx *obj)
{
    delete obj;
}

sfml::sfml()
{
    this->_maxW = 0;
    this->_maxH = 0;
    this->_window = NULL;
}

sfml::sfml(unsigned int w, unsigned int h)
{
    this->_maxW = w;
    this->_maxH = h;
}

sfml::sfml(sfml const &rhs)
{
    *this = rhs;
}

sfml::~sfml()
{

}

sfml &sfml::operator=(sfml const &rhs)
{
    this->_maxW = rhs.getW();
    this->_maxH = rhs.getH();

    return (*this);
}

int sfml::getW() const
{
    return this->_maxW;
}

int sfml::getH() const
{
    return this->_maxH;
}

void    sfml::init(unsigned int &w, unsigned int &h)
{
    _window = new sf::RenderWindow;

    _window->create(sf::VideoMode(w, h), "Nibbler");
    _window->setFramerateLimit(60);
    _window->setVerticalSyncEnabled(true);
    _window->isOpen();
}