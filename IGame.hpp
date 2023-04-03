/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** IGame.hpp
*/

#pragma once
#include "core.hpp"

class image;
class text;

class IGame
{
    public:
        IGame() = default;
        ~IGame() = default;
        virtual void init(std::vector <image> *sprite, std::vector <text> *text) = 0;
        virtual std::string finish() = 0;
        virtual bool quit() = 0;
        virtual std::string input(int input, std::vector <image> *sprite, std::vector <text> *text) = 0;
        virtual void play(std::vector <image> *sprite, std::vector <text> *text) = 0;
};