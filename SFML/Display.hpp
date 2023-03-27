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
#include <map>
#include "../IDisplay.hpp"
#include "Text.hpp"
#include <tuple>

class Display : public IDisplay
{
    public:
    Display(){};
    ~Display(){};
    void openWindow();
    void createText(std::string name, std::string str, int x, int y);
    void drawText(std::string key, int x, int y);
    int event();
    void changeColor(std::string key, int x, int y, std::string color);
    void modifieText(std::string key, int x, int y, std::string newStr);
    void displayWindow();
    void closeWindow();
    void createImage(std::string name, std::string path, int x, int y, char chara) {};
    void drawImage(std::string key, int x, int y, std::string color) {};

    private:
    sf::RenderWindow window;
    std::map<std::string, Text> text;
};
