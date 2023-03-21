/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** core.hpp
*/

#pragma once

#include "openLib.cpp"
#include <dlfcn.h>
#include <iostream>
#include <string>

class Core
{
private:
    
public:
    Core(std::string lib, std::string game, std::string user);
    ~Core(){};
};
