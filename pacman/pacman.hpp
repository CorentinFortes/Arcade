/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** pacman.hpp
*/

#pragma once

#include <iostream>
#include <dlfcn.h>
#include "../IGame.hpp"
#include <cstdlib>
#include "../core.hpp"
#include <fstream>

struct ghost {
    int x, y;
    char direction;
};

class pacman : public IGame
{
private:
    /* data */
    std::string retour;
    bool isQuit = false;
    std::map <std::string, std::string> map;
    int pos_pacman_x;
    int pos_pacman_y;
    char direction;
    ghost ghost1;
    ghost ghost2;
    ghost ghost3;
    ghost ghost4;

public:
    pacman();
    ~pacman();
    void init(std::vector <image> *sprite, std::vector <text> *text);
    std::string input(int input, std::vector <image> *sprite, std::vector <text> *text, int *i);
    void play(std::vector <image> *sprite, std::vector <text> *text);
    ghost decideNextDestination(ghost x);
    std::string finish();
    bool quit();
};

