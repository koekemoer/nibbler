#include <dlfcn.h>
#include <iostream>
#include "Engine.hpp"



int     main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cout << "Enter window Width and Height as arguments" << std::endl;
        return 0;
    }

    Engine  game;

    game.init(itoa(av[1]), itoa(av[2]));

    return (0);


}