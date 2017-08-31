#include <dlfcn.h>
#include <iostream>
#include <string>
#include "Engine.hpp"
#include <unistd.h>



int     main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cout << "Enter window Width and Height as arguments" << std::endl;
        return 0;
    }

    Engine  game;

    game = Engine(atoi(av[1]), atoi(av[2]));
    game.init();
    usleep(50000);

    return (0);


}