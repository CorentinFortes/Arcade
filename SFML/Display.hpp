/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** Display.hpp
*/
#pragma once
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
    void drawText(std::string key, int x, int y) {};
    int event();
    void changeColor(std::string key, int x, int y, std::string color);
    void modifieText(std::string key, int x, int y, std::string newStr);
    void displayWindow();
    void closeWindow();
    void createImage(std::string name, std::string path, int x, int y, char chara, int rotate);
    void drawImage(std::string key, int x, int y, std::string color, char c, int rotate) {};
    void createTexts(std::vector <text> text);
    void createSprites(std::vector <image> sprite);
    void drawSprites(std::vector <image> sprite);
    void drawTexts(std::vector <text> text);

    private:
    sf::RenderWindow window;
    std::map<std::string, Text> textSfml;
    std::map<std::string, Sprites> spriteSfml;
    void setNeWColor(std::string color, Text &text);
    int setRota();
};
