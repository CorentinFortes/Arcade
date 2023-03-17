/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** Text.hpp
*/
#pragma once
#include "Display.hpp"

class Text
{
    public:
    Text(std::string str, int x, int y) {
        pos_y = y;
        std::string path = "lib/Lato-Regular.ttf";
        if (!font.loadFromFile(path)) {
            std::cout << "Error: font not found" << std::endl;
            exit(84);
        }
        text.setFont(font);
        text.setString(str.c_str());
        text.setCharacterSize(36);
        text.setFillColor(sf::Color::White);
        text.setPosition(x, y);
    };
    ~Text() {};
    void changeColor(sf::Color color) {
        text.setFillColor(color);
    };

    public:
    sf::Font font;
    sf::Text text;
    int pos_y;
};
