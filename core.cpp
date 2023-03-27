/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** core.cpp
*/

#include "core.hpp"

typedef IDisplay* (*creator) ();
typedef IGame* (*jeu_menu) (IDisplay *cr);

Core::Core(std::string lib, std::string game, std::string user)
{
    void *handle = openlib(lib.c_str());
    if (!handle)
        return;
    creator create = (creator) dlsym(handle, "create");
    IDisplay *cr = create();
    void *game_ = openlib(game.c_str());
    if (!game_)
        return;
    jeu_menu jeu = (jeu_menu) dlsym(game_, "create");
    IGame *j = jeu(cr);
    bool boolean = j->quit();
    std::string retour = j->finish();
    if (retour.length() > 0) {
        lib = retour.substr(0, retour.find(" "));
        retour.erase(0, retour.find(" ") + 1);
        game = retour.substr(0, retour.find(" "));
        retour.erase(0, retour.find(" ") + 1);
        user = retour.substr(0, retour.find(" "));
    }
    while (boolean == false) {
        void *handle = openlib(lib.c_str());
        if (!handle)
            return;
        creator create = (creator) dlsym(handle, "create");
        IDisplay *cr = create();
        void *game_ = openlib(game.c_str());
        if (!game_)
            return;
        jeu_menu jeu = (jeu_menu) dlsym(game_, "create");
        IGame *j = jeu(cr);
        boolean = j->quit();
        std::string retour = j->finish();
        if (retour.length() > 0) {
            lib = retour.substr(0, retour.find(" "));
            retour.erase(0, retour.find(" ") + 1);
            game = retour.substr(0, retour.find(" "));
            retour.erase(0, retour.find(" ") + 1);
            user = retour.substr(0, retour.find(" "));
        }
    }
}
