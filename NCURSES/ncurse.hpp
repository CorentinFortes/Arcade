#pragma once

#include <iostream>
#include <curses.h>
#include <vector>
#include <string>

#include "../IDisplay.hpp"

class Display : public IDisplay
{
    private:
    // void printMenu(std::vector <std::string> menu, std::vector <std::string> games);
    // std::string printUser();
    WINDOW *window;
    std::map <std::string, std::string> texts;
    std::map <std::string, char> images;

    public:
    Display(){};
    ~Display(){};
    void displayWindow();
    // void printText(std::string str, int x, int y, std::string color);
    void createText(std::string name, std::string str, int x, int y);
    void drawText(std::string key, int x, int y);
    int event();
    void changeColor(std::string key, int x, int y, std::string color);
    void modifieText(std::string key, int x, int y, std::string newStr);
    void openWindow();
    void closeWindow();
    void createImage(std::string name, std::string path, int x, int y, char chara, int rotate);
    void drawImage(std::string key, int x, int y, std::string color, char c, int rotate);
    void createTexts(std::vector <text> text);
    void createSprites(std::vector <image> sprite);
    void drawSprites(std::vector <image> sprite);
    void drawTexts(std::vector <text> text);
};