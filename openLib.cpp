/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** test.cpp
*/

#include <iostream>
#include <dlfcn.h>
#include <vector>
#include "IDisplay.hpp"
#include "IGame.hpp"
#include "core.hpp"

typedef IDisplay* (*creator) ();
typedef IGame* (*jeu_menu) ();

void *openlib(std::string path)
{
    void *handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return NULL;
    }
    return handle;
}

int main (int ac, char **av)
{
    Core core(av[1], "./lib/arcade_menu.so", " ");
    return 0;
}


// int main(int ac, char **av)
// {
//     void *handle = openlib(av[1]);
//     if (!handle)
//         return 84;
//     void *game = openlib("./lib/arcade_menu.so");
//     if (!game)
//         return 84;
//     creator create = (creator) dlsym(handle, "create");
//     IDisplay *cr = create();
//     jeu_menu jeu = (jeu_menu) dlsym(game, "create");
//     IGame *j = jeu();
//     std::string retour = j->finish();
//     if (retour.length() > 0) {
//         std::string lib = retour.substr(0, retour.find(" "));
//         retour.erase(0, retour.find(" ") + 1);
//         std::string game_ = retour.substr(0, retour.find(" "));
//         retour.erase(0, retour.find(" ") + 1);
//         std::string user = retour.substr(0, retour.find(" "));
//         Core core(lib, game_, user);
//     }
//     dlclose(handle);
//     dlclose(game);
//     return 0;
// }
