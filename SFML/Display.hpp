/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** Display.hpp
*/
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <unistd.h>
#include "../IDisplay.hpp"

class Display : public IDisplay
{
    public:
    Display(){};
    ~Display(){};
    virtual void printHello(void);
    virtual std::string createMenu(void);
};
