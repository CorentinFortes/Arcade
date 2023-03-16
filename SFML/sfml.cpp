/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** func.cpp
*/

#include <iostream>
#include "../IDisplay.hpp"

class Display : public IDisplay
{
    public:
    virtual void printHello(void);
    virtual void createMenu(void);
};

void Display::printHello(void)
{
    std::cout << "sfml world" << std::endl;
}

void Display::createMenu(void)
{
    sf::RenderWindow window(sf::VideoMode(800, 700), "SFML menu");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }
}

extern "C" IDisplay* create(void)
{
    return new Display();
}
