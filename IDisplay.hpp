/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** ITest.hpp
*/
#pragma once

class IDisplay
{
    public:
    ~IDisplay() = default;
    virtual void printHello(void) = 0;
    virtual std::string createMenu() = 0;
};
