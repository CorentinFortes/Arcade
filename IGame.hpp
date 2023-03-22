/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** IGame.hpp
*/

#pragma once
#include "IDisplay.hpp"

class IGame
{
    public:
        IGame() = default;
        ~IGame() = default;
        virtual std::string finish() = 0;
        virtual bool quit() = 0;
};

