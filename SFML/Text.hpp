/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** Text.hpp
*/
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <unistd.h>

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

class Sprites
{
    public:
    Sprites() {};
    Sprites(Sprites const& other) {
        sprite.setPosition(other.sprite.getPosition());
    }
    Sprites(std::string path, int x, int y) {
        sf::Vector2f position(x, y);
        sprite.setPosition(position);
    };
    ~Sprites() {};

    public:
    sf::Sprite sprite;
};

class SpriteCreator {

    public:
    SpriteCreator(sf::Texture &texture, sf::Vector2f position) {
        sprite.setTexture(texture);
        sprite.setPosition(position);
    };
    void draw(sf::RenderWindow &window) {
        window.draw(sprite);
    };

    public:
    sf::Sprite sprite;
};
