/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** sdl2.hpp
*/

#pragma once
#include "../IDisplay.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


class Display : public IDisplay
{
    public:
    Display(){};
    ~Display(){};
    void openWindow();
    void closeWindow();
    void displayWindow();
    void createText(std::string name, std::string str, int x, int y);
    void drawText(std::string key, int x, int y);
    int event();
    void changeColor(std::string key, int x, int y, std::string color, std::string name);
    void modifieText(std::string key, int x, int y, std::string newStr);
    void createImage(std::string name, std::string path, int x, int y, char chara) {};
    void drawImage(std::string key, int x, int y, std::string color, char c) {};
    void createTexts(std::vector <text> text);
    void createSprites(std::vector <image> sprite) {};
    void drawSprites(std::vector <image> sprite) {};
    void drawTexts(std::vector <text> text);
 
    private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Color color[6];
    TTF_Font *font;
    std::map<std::string, SDL_Color> _color;
    std::map<std::string, SDL_Texture *> _text;
    std::map<std::string, SDL_Surface *> _surface;
};