/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** ITest.hpp
*/
#pragma once
#include "core.hpp"

class text;
class image;


class IDisplay
{
    public:
    ~IDisplay() = default;
    virtual void openWindow() = 0;
    virtual void createText(std::string name, std::string str, int x, int y) = 0;
    virtual void drawText(std::string key, int x, int y) = 0;
    virtual int event() = 0;
    // virtual void changeColor(std::string key, int x, int y, std::string color) = 0;
    virtual void modifieText(std::string key, int x, int y, std::string newStr) = 0;
    virtual void createImage(std::string name, std::string path, int x, int y, char chara, int rotate) = 0;
    virtual void drawImage(std::string key, int x, int y, std::string color, char c, int rotate) = 0;
    virtual void closeWindow() = 0;
    virtual void displayWindow() = 0;
    virtual void createTexts(std::vector <text> text) = 0;
    virtual void createSprites(std::vector <image> sprite) = 0;
    virtual void drawSprites(std::vector <image> sprite) = 0;
    virtual void drawTexts(std::vector <text> text) = 0;
    // virtual std::string changeLib() = 0;
};

void *openlib(std::string path);
