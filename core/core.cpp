/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** core.cpp
*/

#include "core.hpp"

Core::Core(std::string lib, std::string game, std::string user)
{
    void *handle = openlib(lib.c_str());
    if (!handle)
        return;
    creator create = (creator) dlsym(handle, "create");
    IDisplay *jeu = create();
    
}