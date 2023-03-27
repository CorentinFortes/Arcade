/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** sdl2.cpp
*/

#include "sdl2.hpp"

void Display::openWindow()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 700, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Display::closeWindow()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
}

void Display::displayWindow()
{
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);
}

void Display::createText(std::string name, std::string str, int x, int y)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("lib/Lato-Regular.ttf", 36);
    color[0] = {255, 255, 255, 255};
    color[1] = {255, 0, 0, 255};
    color[2] = {0, 255, 0, 255};
    color[3] = {0, 0, 255, 255};
    color[4] = {255, 255, 0, 255};
    color[5] = {255, 0, 255, 255};
    if (str.length() == 0)
        str = " ";
    else if (str.find('\n') != std::string::npos)
        str = " ";
    _color[name] = color[0];
    _surface[name] = TTF_RenderText_Solid(font, str.c_str(), _color[name]);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, _surface[name]);
    _text[name] = texture;
}

void Display::drawText(std::string key, int x, int y)
{
    if (x == 7)
        x = 100;
    SDL_Rect rect = {x + 10, y * 40, _surface[key]->w, _surface[key]->h};
    SDL_QueryTexture(_text[key], NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, _text[key], NULL, &rect);
    SDL_RenderPresent(renderer);
}

int Display::event()
{
    SDL_Event e;
    while(SDL_PollEvent(&e) > 0) {
        switch(e.type)
        {
            case SDL_QUIT:
                return 1;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        return 1;
                    case SDLK_UP:
                        return 259;
                    case SDLK_DOWN:
                        return 258;
                    case SDLK_RETURN:
                        return 2;
                    case SDLK_BACKSPACE:
                        return 8;
                    case SDLK_a:
                        return 97;
                    case SDLK_b:
                        return 98;
                    case SDLK_c:
                        return 99;
                    case SDLK_d:
                        return 100;
                    case SDLK_e:
                        return 101;
                    case SDLK_f:
                        return 102;
                    case SDLK_g:
                        return 103;
                    case SDLK_h:
                        return 104;
                    case SDLK_i:
                        return 105;
                    case SDLK_j:
                        return 106;
                    case SDLK_k:
                        return 107;
                    case SDLK_l:
                        return 108;
                    case SDLK_m:
                        return 109;
                    case SDLK_n:
                        return 110;
                    case SDLK_o:
                        return 111;
                    case SDLK_p:
                        return 112;
                    case SDLK_q:
                        return 113;
                    case SDLK_r:
                        return 114;
                    case SDLK_s:
                        return 115;
                    case SDLK_t:
                        return 116;
                    case SDLK_u:
                        return 117;
                    case SDLK_v:
                        return 118;
                    case SDLK_w:
                        return 119;
                    case SDLK_x:
                        return 120;
                    case SDLK_y:
                        return 121;
                    case SDLK_z:
                        return 122;
                    default:
                        return 0;
                }
        }
    }
    return -1;
}

void Display::changeColor(std::string key, int x, int y, std::string c)
{
    SDL_FreeSurface(_surface[key]);
    if (c == "red") {
        _color[key] = color[1];
        _surface[key] = TTF_RenderText_Solid(TTF_OpenFont("lib/Lato-Regular.ttf", 36), key.c_str(), _color[key]);
    } if (c == "green") {
        _color[key] = color[2];
        _surface[key] = TTF_RenderText_Solid(TTF_OpenFont("lib/Lato-Regular.ttf", 36), key.c_str(), _color[key]);
    } if (c == "blue") {
        _color[key] = color[3];
        _surface[key] = TTF_RenderText_Solid(TTF_OpenFont("lib/Lato-Regular.ttf", 36), key.c_str(), _color[key]);
    } if (c == "yellow") {
        _color[key] = color[4];
        _surface[key] = TTF_RenderText_Solid(TTF_OpenFont("lib/Lato-Regular.ttf", 36), key.c_str(), _color[key]);
    } if (c == "black") {
        _color[key] = color[5];
        _surface[key] = TTF_RenderText_Solid(TTF_OpenFont("lib/Lato-Regular.ttf", 36), key.c_str(), _color[key]);
    } if (c == "white") {
        _color[key] = color[0];
        _surface[key] = TTF_RenderText_Solid(TTF_OpenFont("lib/Lato-Regular.ttf", 36), key.c_str(), _color[key]);
    }
    SDL_DestroyTexture(_text[key]);
    _text[key] = SDL_CreateTextureFromSurface(renderer, _surface[key]);
}

void Display::modifieText(std::string key, int x, int y, std::string str)
{
    SDL_FreeSurface(_surface[key]);
    _surface[key] = TTF_RenderText_Solid(TTF_OpenFont("lib/Lato-Regular.ttf", 36), str.c_str(), _color[key]);
    SDL_DestroyTexture(_text[key]);
    _text[key] = SDL_CreateTextureFromSurface(renderer, _surface[key]);
}

extern "C" IDisplay* create(void)
{
    return new Display();
}

