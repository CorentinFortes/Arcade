/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** all.hpp
*/

#pragma once
#include "core.hpp"

int findImage(std::string name, std::vector <image> *sprite);
int findText(std::string name, std::vector <text> *text);

class text
{
public:
    std::string name;
    std::string str;
    int x;
    int y;
    std::string color;
    text (std::string name, std::string str, int x, int y, std::string color) 
    : name(name), str(str), x(x), y(y), color(color) {};
    ~text () {};
};

class image
{
public:
    std::string name;
    std::string path;
    int x;
    int y;
    char chara;
    std::string color;
    image (std::string name, std::string path, int x, int y, char chara, std::string color) 
    : name(name), path(path), x(x), y(y), chara(chara), color(color) {};
    ~image () {};
};

