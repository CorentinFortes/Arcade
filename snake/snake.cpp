/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** snake.cpp
*/

#include "snake.hpp"


snake::snake(IDisplay *snake)
{
    snake->openWindow();
    while (1) {
        snake->createImage("snake", "snake/snake.png", 0, 0, 's');
        snake->createImage("food", "snake/food.png", 0, 0, 'f');
        snake->drawImage("snake", 1, 1, "blue");
        snake->drawImage("food", 2, 2, "blue");
        snake->displayWindow();
    }
}

snake::~snake()
{
}

extern "C" snake* create(IDisplay *cr)
{
    return new snake(cr);
}

extern "C" bool islib()
{
    return false;
}