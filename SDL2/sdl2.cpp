/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** sdl2.cpp
*/

#include "sdl2.hpp"

std::string Display::createMenu()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 700, 0);
    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    bool keep_window_open = true;
    while(keep_window_open) {
        SDL_Event e;
        while(SDL_PollEvent(&e) > 0) {
            switch(e.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
            SDL_UpdateWindowSurface(window);
        }
    }
    return "sdl2 lib.so";
}

extern "C" IDisplay* create(void)
{
    return new Display();
}
