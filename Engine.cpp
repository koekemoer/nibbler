#include "Engine.hpp"

Engine::Engine() : 
    _winWidth(0),
    _winHeight(0),
   // _score = 0,
    handle(NULL)
{

}

Engine::~Engine()
{

}

Engine::Engine(unsigned int w, unsigned int h)
{
    this->_winWidth = w;
    this->_winHeight = h;
}

Engine::Engine(const Engine &rhs)
{
    *this = rhs;
}

Engine &Engine:: operator=(const Engine &rhs)
{
    this->_winWidth = rhs.getWinWidth();
    this->_winHeight = rhs.getWinHeight();
    return (*this);
}

int    Engine::getWinWidth() const
{
    return this->_winWidth;
}

int    Engine::getWinHeight() const
{
    return this->_winHeight;
}

void     Engine::setWinWidth(int width)
{
    this->_winWidth = width;
}

void     Engine::setWinHeight(int height)
{
    this->_winHeight = height;
}

void    Engine::loadLib(int gui)
{
    switch (gui)
    {
        case 1:
        {
            std::cout << "Starting SDL2" << std::endl;
            this->handle = dlopen("lib1.so", RTLD_LAZY);
            create_t* create_lib = (create_t *) dlsym(this->handle, "create");
            const char* dlsym_error = dlerror();
            if (dlsym_error)
                throw (dlsym_error);

            this->lib = create_lib();
            //this->lib
            break;
        }
        case 2:
        {
            std::cout << "Starting SFML" << std::endl;
            this->handle = dlopen("./lib2.so", RTLD_LAZY);
            create_t* create_lib = (create_t *) dlsym(this->handle, "create");
            const char* dlsym_error = dlerror();
            if (dlsym_error)
                throw (dlsym_error);
            this->lib = create_lib();
            break;
        }
        default:
        {
            std::cout << "Invalid input" << std::endl;
        }
        this->lib->init(this->_winWidth, this->_winHeight);
            //throw ("library initialization Error: \"failed.\"");
    }
}

void    Engine::init(unsigned int w, unsigned int h)
{
    this->_winWidth = w;
    this->_winHeight = h;
    loadLib(1);
}

void    Engine::gameLoop()
{
    while (1)
    {
        this->lib->render();
        usleep(50000);
    }
}