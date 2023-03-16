/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** func.cpp
*/
#include "Display.hpp"

void Display::printHello(void)
{
    std::cout << "sfml world" << std::endl;
}

std::string Display::createMenu(void)
{
    sf::RenderWindow window(sf::VideoMode(800, 700), "SFML menu");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return "close";
            }
        }

        window.display();
    }
    return "close";
}

extern "C" IDisplay* create(void)
{
    return new Display();
}
