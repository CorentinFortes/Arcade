/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** ITest.hpp
*/
#pragma once
#include <iostream>
#include <string>
#include <map>


class IDisplay
{
    public:
    ~IDisplay() = default;
    virtual void openWindow() = 0;
    virtual std::string createText(std::string name, int x, int y) = 0;
    virtual void drawText(std::string key, int x, int y) = 0;
    virtual char event() = 0;
    virtual void changeColor(std::string key, int x, int y, std::string color) = 0;
    virtual void modifieText(std::string key, int x, int y, std::string newStr) = 0;
};
