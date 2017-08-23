#include "sfml.hpp"

SFML::SFML()
{
    this->_w = 0;
    this->_h = 0;
    this->_window = nullptr;
}

SFML::SFML(unsigned int w, unsigned int h)
{
    this->_w = w;
    this->_h = h;
}

SFML::~SFML()
{

}

void    SFML::init(unsigned int &w, unsigned int &h)
{
    _window = new sf::RenderWindow;

    _window->create(sf::VideoMode(w, h), "Nibbler");
    _window->setFramerateLimit(60);
    _window->setVerticalSyncEnabled(true);
    _window->isOpen();
}