/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** test.cpp
*/

#include <iostream>
#include <dlfcn.h>
#include <vector>
#include "IDisplay.hpp"
#include "IGame.hpp"

typedef IDisplay* (*creator) ();
typedef IGame* (*jeu_menu) (IDisplay *cr);

void *openlib(std::string path)
{
    void *handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return NULL;
    }
    return handle;
}

std::string printUser(IDisplay *menu)
{
    std::string user;
    menu->createText("user", user, 0, 0);
    while (1) {
        int ch = menu->event();
        if (ch == 1 || ch == 2) {
            return(user);
        }
        if (ch >= 97 && ch <= 122)
            user += ch;
        if (ch >= 65 && ch <= 90)
            user += ch;
        if (ch == 263) {
            if (user.size() > 0)
                user.pop_back();
            menu->modifieText("user", 7, 14, user);
        }
        menu->modifieText("user", 7, 14, user);
        menu->displayWindow();
    }
}

int main(int ac, char **av)
{
    void *handle = openlib(av[1]);
    if (!handle)
        return 84;
    void *game = openlib("./lib/arcade_menu.so");
    if (!game)
        return 84;
    creator create = (creator) dlsym(handle, "create");
    IDisplay *cr = create();
    jeu_menu jeu = (jeu_menu) dlsym(game, "create");
    IGame *j = jeu(cr);
    // std::string retour;
    // std::vector <std::string> libs = {"./lib/arcade_ncurses.so", "./lib/arcade_sdl.so", "./lib/arcade_sfml.so"};
    // std::vector <std::string> games = {"./lib/arcade_centipede.so", "./lib/arcade_menu.so", "./lib/nibbler.so",
    // "./lib/arcade_pacman.so", "./lib/arcade_qix.so", "./lib/arcade_snake.so" , "./lib/arcade_solarfox.so"};
    // int selectgame = -1, selectlib = -1, surligne = 1;
    // menu->openWindow();
    // while (1) {
    //     menu->createText("Choose a lib :", "Choose a lib :", 0, 0);
    //     menu->createText(libs[0], libs[0], 0, 1);
    //     menu->createText(libs[1], libs[1], 0, 2);
    //     menu->createText(libs[2], libs[2], 0, 3);
    //     menu->createText("\n 1", "\n", 0, 4);
    //     menu->createText("Choose a game :", "Choose a game :", 0, 5);
    //     menu->createText(games[0], games[0], 0, 6);
    //     menu->createText(games[1], games[1], 0, 7);
    //     menu->createText(games[2], games[2], 0, 8);
    //     menu->createText(games[3], games[3], 0, 9);
    //     menu->createText(games[4], games[4], 0, 10);
    //     menu->createText(games[5], games[5], 0, 11);
    //     menu->createText(games[6], games[6], 0, 12);
    //     menu->createText("\n 2", "\n", 0, 13);
    //     menu->createText("User : ", "User : ", 0, 14);
    //     menu->drawText("Choose a lib :", 0, 0);
    //     menu->drawText(libs[0], 0, 1);
    //     menu->drawText(libs[1], 0, 2);
    //     menu->drawText(libs[2], 0, 3);
    //     menu->drawText("\n 1", 0, 4);
    //     menu->drawText("Choose a game :", 0, 5);
    //     menu->drawText(games[0], 0, 6);
    //     menu->drawText(games[1], 0, 7);
    //     menu->drawText(games[2], 0, 8);
    //     menu->drawText(games[3], 0, 9);
    //     menu->drawText(games[4], 0, 10);
    //     menu->drawText(games[5], 0, 11);
    //     menu->drawText(games[6], 0, 12);
    //     menu->drawText("\n 2", 0, 13);
    //     menu->drawText("User : ", 0, 14);
    //     if (surligne != -1) {
    //         if (surligne < 4)
    //             menu->changeColor(libs[surligne - 1], 0, surligne, "white");
    //         if (surligne > 5)
    //             menu->changeColor(games[surligne - 6], 0, surligne, "white");
    //     }
    //     if (selectlib != -1)
    //         menu->changeColor(libs[selectlib - 1], 0, selectlib, "yellow");
    //     if (selectgame != -1)
    //         menu->changeColor(games[selectgame - 6], 0, selectgame, "yellow");
        
        
    //     int ch = menu->event();
    //     if (ch == 2) {
    //         if (surligne < 4)
    //             selectlib = surligne;
    //         if (surligne > 5)
    //             selectgame = surligne;
    //         if (selectlib != -1 && selectgame != -1) {
    //             retour += printUser(menu);
    //             menu->closeWindow();
    //             break;
    //             // return (games[selectgame - 6] + " " + menu[selectlib - 1] + " " + retour);
    //         }
    //     }
    //     if (ch == 1) {
    //         menu->closeWindow();
    //         break;
    //     }
    //     if (ch == 259) {
    //         if (surligne == 6)
    //             surligne = 3;
    //         else if (surligne > 1)
    //             surligne--;
    //     }
    //     if (ch == 258) {
    //         if (surligne == 3)
    //             surligne = 6;
    //         else if (surligne < 12)
    //             surligne++;
    //     }
    // }

    // std::string buf = menu->createMenu();
    // std::string game = buf.substr(0, buf.find(" "));
    // buf.erase(0, buf.find(" ") + 1);
    // std::string lib = buf.substr(0, buf.find(" "));
    // buf.erase(0, buf.find(" ") + 1);
    // std::string name = buf.substr(0, buf.find(" "));
    // delete menu;
    dlclose(handle);
    return 0;
}