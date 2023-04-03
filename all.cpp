/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** all.cpp
*/

#include "all.hpp"

int findImage(std::string name, std::vector <image> *sprite)
{
    for (int i = 0; i < sprite->size(); i++) {
        if (sprite->at(i).name == name)
            return (i);
    }
    return (-1);
}

int findText(std::string name, std::vector <text> *text)
{
    for (int i = 0; i < text->size(); i++) {
        if (text->at(i).name == name)
            return (i);
    }
    return (-1);
}
