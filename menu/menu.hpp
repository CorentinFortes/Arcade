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
#include "../IGame.hpp"
#include "../core.hpp"

class menu : public IGame
{
    private:
        std::string printUser(IDisplay *menu, std::vector <std::string> libs, std::vector <std::string> games, int selectlib, int selectgame);
        int max_lib = 0, max_game = 0, max_tot = 0;
        int selectgame = -1, selectlib = -1, surligne = 2;
        std::vector <std::string> games;
        std::vector <std::string> libs;
        std::string user;
        bool isSelected = false;

    public:
        menu(){};
        ~menu(){};
        void init(std::vector <image> *sprite, std::vector <text> *text);
        std::string finish();
        bool quit();
        std::string input(int input, std::vector <image> *sprite, std::vector <text> *text);
        void play(std::vector <image> *sprite, std::vector <text> *text);

    public:
    std::string retour;
    bool isQuit;
};
