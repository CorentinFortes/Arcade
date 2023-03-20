/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** menu.hpp
*/

#pragma once
#include <iostream>
#include <dlfcn.h>
#include "../IDisplay.hpp"

class menu
{
    private:
        std::string printUser(IDisplay *menu);

    public:
        menu(IDisplay *display);
        ~menu() {};
};
