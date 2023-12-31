/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** core.hpp
*/
#include <dlfcn.h>
#include <iostream>
#include <string>
#include <map>
#include <chrono>
#include <thread>
#include <vector>

#pragma once

#include "IDisplay.hpp"
#include "IGame.hpp"
#include "all.hpp"
// #include "openLib.cpp"

class IGame;
class IDisplay;
typedef IDisplay* (*creator) ();
typedef bool* (*typelib) ();
typedef IGame* (*jeu_menu) ();

class Core
{
    public:
    IGame *game;
    IDisplay *display;
    creator create;
    Core(std::string lib, std::string game, std::string user);
    ~Core(){};
    void openLibs(std::string lib, std::string game, std::string user);
    std::string changelib(std::string *lib);
};
