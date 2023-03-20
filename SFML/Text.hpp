/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** Text.hpp
*/
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <unistd.h>

class A {

    public:
    A() {};
    ~A() {
        std::cout << "A destructor" << std::endl;
    }
};

class Text
{
    public:
    Text() {};
    Text(Text const& other) {
        txt.setFont(*loadUniqueFont());
        txt.setString(other.txt.getString());
        txt.setCharacterSize(other.txt.getCharacterSize());
        txt.setFillColor(other.txt.getFillColor());
        txt.setPosition(other.txt.getPosition());
    }
    Text(std::string str, int x, int y) {
        txt.setFont(*loadUniqueFont());
        txt.setString(str.c_str());
        txt.setCharacterSize(36);
        txt.setFillColor(sf::Color::White);
        txt.setPosition(x, y);
    };
    ~Text() {};

    public:
        sf::Font* loadUniqueFont() {
            static sf::Font font;
            static bool loaded = false;
            std::string path = "lib/Lato-Regular.ttf";
            if (!loaded) {
                if (!font.loadFromFile(path)) {
                    std::cout << "Error: font not found" << std::endl;
                    exit(84);
                }
                loaded = true;
            }
            return &font;
        }

    sf::Text txt;
};

