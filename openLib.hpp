/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** openLib.hpp
*/

#pragma once

#include <iostream>
#include <dlfcn.h>
#include <vector>
#include "IDisplay.hpp"
#include "IGame.hpp"

typedef IDisplay* (*creator) ();
typedef IGame* (*jeu_menu) (IDisplay *cr);
void *openlib(std::string path);
std::string printUser(IDisplay *menu);