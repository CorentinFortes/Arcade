/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** snake.hpp
*/

#pragma once

#include <iostream>
#include <dlfcn.h>
#include "../IGame.hpp"
#include "../core.hpp"

class Queue
{
    public:
        int num;
        int x;
        int y;
        Queue(int num, int x, int y);
        ~Queue() {};
};

class snake : public IGame
{
    private:
        int pos_snake_x;
        int pos_snake_y;
        int pos_food_x;
        int pos_food_y;
        char direction;
        std::string retour;
        bool isQuit;
        int score;
        std::vector <Queue> queue;

    public:
        snake() : isQuit(false), pos_snake_x(1), pos_snake_y(1), pos_food_x(15), pos_food_y(5), direction('d'), score(0) {};
        ~snake();
        void init(std::vector <image> *sprite, std::vector <text> *text);
        std::string input(int input, std::vector <image> *sprite, std::vector <text> *text);
        void play(std::vector <image> *sprite, std::vector <text> *text);
        std::string finish();
        bool quit();
};
