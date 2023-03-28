/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** func.cpp
*/

#include "Display.hpp"

void Display::openWindow()
{
    window.create(sf::VideoMode(800, 700), "SFML menu");
}

void Display::closeWindow()
{
    window.close();
}

void Display::displayWindow()
{
    window.display();
    window.clear();
}

void Display::createText(std::string name, std::string str, int x, int y)
{
    x = x + 10;
    y = y * 35;
    text[name] = Text(str,x,y);
}

void Display::drawText(std::string key, int x, int y)
{
    window.draw(text[key].txt);
}

int Display::event()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            return 1;
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            return 2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            return 259;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            return 258;
        if (event.type == sf::Event::TextEntered)
            return event.text.unicode;
    }
    return -1;
}

void Display::changeColor(std::string key, int x, int y, std::string color)
{
    if (color == "red")
        text[key].txt.setFillColor(sf::Color::Red);
    if (color == "green")
        text[key].txt.setFillColor(sf::Color::Green);
    if (color == "blue")
        text[key].txt.setFillColor(sf::Color::Blue);
    if (color == "white")
        text[key].txt.setFillColor(sf::Color::White);
    if (color == "yellow")
        text[key].txt.setFillColor(sf::Color::Yellow);
    if (color == "black")
        text[key].txt.setFillColor(sf::Color::Black);
}

void Display::modifieText(std::string key, int x, int y, std::string newStr)
{
    // window.clear();
    text[key].txt.setString(newStr);
}

extern "C" IDisplay* create(void)
{
    return new Display();
}

extern "C" bool islib()
{
    return true;
}