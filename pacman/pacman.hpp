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
#include "../core.hpp"
#include <fstream>

class pacman : public IGame
{
private:
    /* data */
    std::string retour;
    bool isQuit = false;
    int pos_pacman_x;
    int pos_pacman_y;
    char direction;

public:
    pacman(/* args */);
    ~pacman();
    void init(std::vector <image> *sprite, std::vector <text> *text);
    std::string input(int input, std::vector <image> *sprite, std::vector <text> *text, int *i);
    void play(std::vector <image> *sprite, std::vector <text> *text);
    std::string finish();
    bool quit();
};

