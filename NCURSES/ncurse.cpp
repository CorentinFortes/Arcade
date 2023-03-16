/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** func.cpp
*/

#include "ncurse.hpp"

void Display::printHello(void)
{
    std::cout << "ncurse world" << std::endl;
}

std::string Display::createMenu(void)
{
    return "close";
}

extern "C" IDisplay* create(void)
{
    return new Display();
}