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
    window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1800, 700, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Init();
    color[0] = {255, 255, 255, 255};
    color[1] = {255, 0, 0, 255};
    color[2] = {0, 255, 0, 255};
    color[3] = {0, 0, 255, 255};
    color[4] = {255, 255, 0, 255};
    color[5] = {255, 0, 255, 255};
    font = TTF_OpenFont("lib/Lato-Regular.ttf", 36);
}

void Display::closeWindow()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void Display::displayWindow()
{
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
}

void Display::createText(std::string name, std::string str, int x, int y)
{
    if (str.length() <= 1)
        _surface[name] = TTF_RenderText_Solid(font, " ", _color[name]);
    else if (str.find('\n') != std::string::npos)
        _surface[name] = TTF_RenderText_Solid(font, " ", _color[name]);
    else
        _surface[name] = TTF_RenderText_Solid(font, str.c_str(), _color[name]);
    _color[name] = color[0];
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, _surface[name]);
    _text[name] = texture;
}

void Display::createTexts(std::vector <text> text)
{
    for (int i = 0; i < text.size(); i++) {
        createText(text[i].name, text[i].str, text[i].x, text[i].y);
    }
}

void Display::drawText(std::string key, int x, int y)
{
    if (x == 7)
        x = 100;
    SDL_Rect rect = {x + 10, y * 40, _surface[key]->w, _surface[key]->h};
    // SDL_QueryTexture(_text[key], NULL, NULL, &rect.w, &rect.h);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderCopy(renderer, _text[key], NULL, &rect);
}

void Display::drawTexts(std::vector <text> text)
{
    for (int i = 0; i < text.size(); i++) {
        changeColor(text[i].name, text[i].x, text[i].y, text[i].color, text[i].str);
        drawText(text[i].name, text[i].x, text[i].y);
    }
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
                    case SDLK_LEFT:
                        return 260;
                    case SDLK_RIGHT:
                        return 261;
                    case SDLK_RETURN:
                        return 2;
                    case SDLK_BACKSPACE:
                        return 8;
                    case SDLK_TAB:
                        return 9;
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
                        return -1;
                }
        }
    }
    return -1;
}

void Display::changeColor(std::string key, int x, int y, std::string c, std::string name)
{
    SDL_FreeSurface(_surface[key]);
    SDL_DestroyTexture(_text[key]);
    if (name.length() <= 1)
        name = " ";
    if (c == "red") {
        _color[key] = color[1];
        _surface[key] = TTF_RenderText_Solid(font, name.c_str(), _color[key]);
    } if (c == "green") {
        _color[key] = color[2];
        _surface[key] = TTF_RenderText_Solid(font, name.c_str(), _color[key]);
    } if (c == "blue") {
        _color[key] = color[3];
        _surface[key] = TTF_RenderText_Solid(font, name.c_str(), _color[key]);
    } if (c == "yellow") {
        _color[key] = color[4];
        _surface[key] = TTF_RenderText_Solid(font, name.c_str(), _color[key]);
    } if (c == "pink") {
        _color[key] = color[5];
        _surface[key] = TTF_RenderText_Solid(font, name.c_str(), _color[key]);
    } if (c == "white") {
        _color[key] = color[0];
        _surface[key] = TTF_RenderText_Solid(font, name.c_str(), _color[key]);
    }
    // SDL_DestroyTexture(_text[key]);
    _text[key] = SDL_CreateTextureFromSurface(renderer, _surface[key]);
}

void Display::modifieText(std::string key, int x, int y, std::string str)
{
    SDL_FreeSurface(_surface[key]);
    _surface[key] = TTF_RenderText_Solid(TTF_OpenFont("lib/Lato-Regular.ttf", 36), str.c_str(), _color[key]);
    SDL_DestroyTexture(_text[key]);
    _text[key] = SDL_CreateTextureFromSurface(renderer, _surface[key]);
    SDL_RenderClear(renderer);
}

void Display::createImage(std::string name, std::string path, int x, int y, char chara, int rotate)
{
    _surfaceSprite[name] = IMG_Load(path.c_str());
    _texture[name] = SDL_CreateTextureFromSurface(renderer, _surfaceSprite[name]);
}

void Display::createSprites(std::vector <image> sprite)
{
    for (int i = 0; i < sprite.size(); i++) {
        createImage(sprite[i].name, sprite[i].path, sprite[i].x, sprite[i].y, sprite[i].chara, sprite[i].rotate);
    }
}

void Display::drawImage(std::string name, int x, int y, std::string color, char chara, int rotate)
{
    int spriteWidth, spriteHeight;
    SDL_QueryTexture(_texture[name], NULL, NULL, &spriteWidth, &spriteHeight);
    SDL_Rect rect;
    rect.x = x * 20;
    rect.y = y * 30;
    rect.w = spriteWidth;
    rect.h = spriteHeight;
    angle = rotate;
    SDL_Point rotationPoint = { rect.w / 2, rect.h / 2 };
    SDL_RenderCopyEx(renderer, _texture[name], NULL, &rect, angle, &rotationPoint, SDL_FLIP_NONE);
    // SDL_RenderCopy(renderer, _texture[name], NULL, &rect);
}

void Display::drawSprites(std::vector <image> sprite)
{
    if (_surfaceSprite.size() < sprite.size()) {
        createImage(sprite[sprite.size() - 1].name, sprite[sprite.size() - 1].path, sprite[sprite.size() - 1].x, sprite[sprite.size() - 1].y, sprite[sprite.size() - 1].chara, sprite[sprite.size() - 1].rotate);
    }
    for (int i = 0; i < sprite.size(); i++) {
        drawImage(sprite[i].name, sprite[i].x, sprite[i].y, sprite[i].color , sprite[i].chara, sprite[i].rotate);
    }
}

extern "C" IDisplay* create(void)
{
    return new Display();
}

extern "C" bool islib()
{
    return true;
}