/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** sdl2.hpp
*/
#pragma once
#include "../IDisplay.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>


class Display : public IDisplay
{
public:
    Display(){};
    ~Display(){};
    std::string createMenu(void);
};