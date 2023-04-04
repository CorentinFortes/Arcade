/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** snake.cpp
*/

#include "snake.hpp"

// std::string printmap()
// {

// }

// snake::snake(IDisplay *snake)
// {
//     snake->openWindow();
//     while (1) {
//         snake->createImage("snake", "snake/snake.png", 0, 0, 's');
//         snake->createImage("food", "snake/food.png", 0, 0, 'f');
//         snake->drawImage("snake", 1, 1, "blue");
//         snake->drawImage("food", 2, 2, "blue");
//         snake->displayWindow();
//     }
// }

Queue::Queue(int num, int x, int y)
{
    this->num = num;
    this->x = x;
    this->y = y;
}

snake::~snake()
{
}

void snake::init(std::vector <image> *sprite, std::vector <text> *textt)
{
    (*textt).push_back(text("map0", "/----------------------------------------------------------\\", 0, 0,"white"));
    for (int i = 0; i < 15; i++) {
        (*textt).push_back(text("map1", "|", 0, i + 1,"white"));
        (*textt).push_back(text("map2", "|", 59, i + 1,"white"));
    }
    (*textt).push_back(text("map0", "\\----------------------------------------------------------/", 0, 16,"white"));
    (*sprite).push_back(image("snake_h", "", 1, 1, '>', "green"));
    (*sprite).push_back(image("food", "", 15, 5, 'O', "red"));
}

std::string snake::input(int ch, std::vector <image> *sprite, std::vector <text> *textt)
{
    if (ch == 1) {
        isQuit = true;
        return "";
    }
    if (ch == 259) {
        direction = 'b';
    }
    if (ch == 258) {
        direction = 'h';
    }
    if (ch == 260) {
        direction = 'g';
    }
    if (ch == 261) {
        direction = 'd';
    }
    return ("");
}

void snake::play(std::vector <image> *sprite, std::vector <text> *text)
{
    if (direction == 'h') {
        pos_snake_y += 1;
    }
    if (direction == 'b') {
        pos_snake_y -= 1;
    }
    if (direction == 'd') {
        pos_snake_x += 1;
    }
    if (direction == 'g') {
        pos_snake_x -= 1;
    }
    if (pos_snake_x > 58 || pos_snake_x < 1 || pos_snake_y > 15 || pos_snake_y < 1) {
        isQuit = true;
    }
    sprite->at(findImage("snake_h", sprite)).x = pos_snake_x;
    sprite->at(findImage("snake_h", sprite)).y = pos_snake_y;
    sprite->at(findImage("food", sprite)).x = pos_food_x;
    sprite->at(findImage("food", sprite)).y = pos_food_y;
    if (pos_snake_x == pos_food_x && pos_snake_y == pos_food_y) {
        pos_food_x = rand() % 58 + 1;
        pos_food_y = rand() % 15 + 1;
        score += 1;
    }
}

bool snake::quit()
{
    return isQuit;
}

std::string snake::finish()
{
    return retour;
}

extern "C" snake* create()
{
    return new snake();
}

extern "C" bool islib()
{
    return false;
}