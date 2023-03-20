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
#include <vector>


class IDisplay
{
    public:
    ~IDisplay() = default;
    virtual void openWindow() = 0;
    virtual void createText(std::string name, std::string str, int x, int y) = 0;
    virtual void drawText(std::string key, int x, int y) = 0;
    virtual int event() = 0;
    virtual void changeColor(std::string key, int x, int y, std::string color) = 0;
    virtual void modifieText(std::string key, int x, int y, std::string newStr) = 0;
    virtual void closeWindow() = 0;
    virtual void displayWindow() = 0;
};
