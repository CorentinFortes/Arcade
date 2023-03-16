/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** func.cpp
*/

#include <iostream>
#include <ncurses.h>
#include "../IDisplay.hpp"

class Display : public IDisplay
{
    public:
    virtual void printHello(void);
    virtual void createMenu();
};

void Display::printHello(void)
{
    std::cout << "ncurse world" << std::endl;
}

void Display::createMenu()
{
    ;
}

extern "C" IDisplay* create()
{
    return new Display();
}