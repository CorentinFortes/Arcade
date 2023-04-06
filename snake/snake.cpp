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
    for (int i = 0; i < 60; i++) {
        if (i == 0) {
            (*sprite).push_back(image("map0", "SFML/board.png", i, 0, '/', "white", 0));
            (*sprite).push_back(image("map3", "SFML/board.png", i, 16, '\\', "white", 0));
        } else if (i == 59) {
            (*sprite).push_back(image("map0", "SFML/board.png", i, 0, '\\', "white", 0));
            (*sprite).push_back(image("map3", "SFML/board.png", i, 16, '/', "white", 0));
        } else {
            (*sprite).push_back(image("map0", "SFML/board.png", i, 0, '-', "white", 0));
            (*sprite).push_back(image("map3", "SFML/board.png", i, 16, '-', "white", 0));
        }
   }
    for (int i = 0; i < 15; i++) {
        (*sprite).push_back(image("map1", "SFML/board.png", 0, i + 1, '|', "white", 0));
        (*sprite).push_back(image("map2", "SFML/board.png", 59, i + 1, '|', "white", 0));
    }
    (*sprite).push_back(image("snake_0", "SFML/snakehead.png", 25, 8, '>', "green", 270));
    (*sprite).push_back(image("food", "SFML/pngegg.png", 15, 5, 'O', "red", 0));
    (*sprite).push_back(image("snake_1", "SFML/snakecorps.png", 25, 8, '*', "green", 270));
    (*sprite).push_back(image("snake_2", "SFML/snakecorps.png", 25, 8, '*', "green", 270));
    (*sprite).push_back(image("snake_3", "SFML/snakecorps.png", 25, 8, '*', "green", 270));
}

std::string snake::input(int ch, std::vector <image> *sprite, std::vector <text> *textt)
{
    if (ch == 1) {
        isQuit = true;
        return "";
    }
    if (ch == 259 && direction != 'h') {
        for (auto &i : (*sprite)) {
            if (i.name != "food") {
                i.rotate = 180;
            }
        }
        direction = 'b';
    }
    if (ch == 258 && direction != 'b') {
        for (auto &i : (*sprite)) {
            if (i.name != "food") {
                i.rotate = 0;
            }
        }
        direction = 'h';
    }
    if (ch == 260 && direction != 'd') {
        for (auto &i : (*sprite)) {
            if (i.name != "food") {
                i.rotate = 90;
            }
        }
        direction = 'g';
    }
    if (ch == 261 && direction != 'g') {
        for (auto &i : (*sprite)) {
            if (i.name != "food") {
                i.rotate = 270;
            }
        }
        direction = 'd';
    }
    return ("");
}

void snake::play(std::vector <image> *sprite, std::vector <text> *text)
{
    if (direction == 'h') {
        sprite->at(findImage("snake_0", sprite)).chara = 'v';
        pos_snake_y += 1;
    }
    if (direction == 'b') {
        sprite->at(findImage("snake_0", sprite)).chara = '^';
        pos_snake_y -= 1;
    }
    if (direction == 'd') {
        sprite->at(findImage("snake_0", sprite)).chara = '>';
        pos_snake_x += 1;
    }
    if (direction == 'g') {
        sprite->at(findImage("snake_0", sprite)).chara = '<';
        pos_snake_x -= 1;
    }
    if (pos_snake_x > 59 || pos_snake_x < 1 || pos_snake_y > 15 || pos_snake_y < 1) {
        isQuit = true;
        return;
    }
    for (int i = score; i >= 1; i--) {
        std::string name = "snake_" + std::to_string(i);
        sprite->at(findImage(name, sprite)).x = sprite->at(findImage("snake_" + std::to_string(i - 1), sprite)).x;
        sprite->at(findImage(name, sprite)).y = sprite->at(findImage("snake_" + std::to_string(i - 1), sprite)).y;
    }
    // for (int i = 1; i <= score; i++) {
    //     std::string name = "snake_" + std::to_string(i);
    //     sprite->at(findImage(name, sprite)).x = sprite->at(findImage("snake_" + std::to_string(i - 1), sprite)).x;
    //     sprite->at(findImage(name, sprite)).y = sprite->at(findImage("snake_" + std::to_string(i - 1), sprite)).y;
    // }
    sprite->at(findImage("snake_0", sprite)).x = pos_snake_x;
    sprite->at(findImage("snake_0", sprite)).y = pos_snake_y;
    sprite->at(findImage("food", sprite)).x = pos_food_x;
    sprite->at(findImage("food", sprite)).y = pos_food_y;
    // for (int i = 1; i <= score; i++) {
    //     std::string name = "snake_" + std::to_string(i);
    //     int x = sprite->at(findImage("snake_" + std::to_string(i), sprite)).x;
    //     int y = sprite->at(findImage("snake_" + std::to_string(i), sprite)).x;
    //     if (x == pos_snake_x && y == pos_snake_y) {
    //         isQuit = true;
    //     }
    // }
    for (int i = score; i >= 1; i--) {
        std::string name = "snake_" + std::to_string(i);
        if (sprite->at(findImage(name, sprite)).x == pos_snake_x && sprite->at(findImage(name, sprite)).y == pos_snake_y) {
            isQuit = true;
        }
    }
    if (pos_snake_x == pos_food_x && pos_snake_y == pos_food_y) {
        pos_food_x = rand() % 54 + 2;
        pos_food_y = rand() % 15 + 1;
        score += 1;
        std::string name = "snake_" + std::to_string(score);
        (*sprite).push_back(image(name, "SFML/snakecorps.png", pos_snake_x, pos_snake_y, '*', "green", 270));
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