/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** Display.hpp
*/

#include <iostream>
#include "../IDisplay.hpp"

class Display : public IDisplay
{
    public:
    virtual void printHello(void);
    virtual std::string createMenu(void);
};
