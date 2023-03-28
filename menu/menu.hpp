/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** menu.hpp
*/

#pragma once
#include <iostream>
#include <dlfcn.h>
#include <cstring>
#include <dirent.h>
#include "../IDisplay.hpp"
#include "../IGame.hpp"
#include "../core.hpp"

class menu : public IGame
{
    private:
        std::string printUser(IDisplay *menu, std::vector <std::string> libs, std::vector <std::string> games, int selectlib, int selectgame);
        int max_lib = 0, max_game = 0, max_tot = 0;

    public:
        menu(IDisplay *display);
        ~menu(){};
        std::string finish();
        bool quit();

    public:
    std::string retour;
    bool isQuit;
};
