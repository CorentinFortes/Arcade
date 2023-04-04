/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** core.cpp
*/

#include "core.hpp"

typedef IDisplay* (*creator) ();
typedef IGame* (*jeu_menu) ();

void Core::openLibs(std::string libr, std::string gamee, std::string user)
{
    void *handle = openlib(libr.c_str());
    if (!handle)
        return;
    creator create = (creator) dlsym(handle, "create");
    display = create();
    void *game_ = openlib(gamee.c_str());
    if (!game_)
        return;
    jeu_menu jeu = (jeu_menu) dlsym(game_, "create");
    game = jeu();
}

Core::Core(std::string lib, std::string gamee, std::string user)
{
    openLibs(lib, gamee, user);
    display->openWindow();
    std::vector <text> text;
    std::vector <image> sprite;
    std::string retour = "";
    game->init(&sprite, &text);
    display->createTexts(text);
    display->createSprites(sprite);
    while (game->quit() == false) {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        display->drawTexts(text);
        display->drawSprites(sprite);
        retour = game->input(display->event(), &sprite, &text);
        game->play(&sprite, &text);
        display->displayWindow(); 
    }
    if (retour != "") {
        user = retour.substr(0, retour.find(" "));
        retour.erase(0, retour.find(" ") + 1);
        lib = retour.substr(0, retour.find(" "));
        retour.erase(0, retour.find(" ") + 1);
        gamee = retour.substr(0, retour.find(" "));
        Core(lib, gamee, user);
    }
    display->closeWindow();
}


// Core::Core(std::string lib, std::string game, std::string user)
// {
//     void *handle = openlib(lib.c_str());
//     if (!handle)
//         return;
//     creator create = (creator) dlsym(handle, "create");
//     IDisplay *cr = create();
//     void *game_ = openlib(game.c_str());
//     if (!game_)
//         return;
//     jeu_menu jeu = (jeu_menu) dlsym(game_, "create");
//     IGame *j = jeu(cr);
//     bool boolean = j->quit();
//     std::string retour = j->finish();
//     if (retour.length() > 0) {
//         lib = retour.substr(0, retour.find(" "));
//         retour.erase(0, retour.find(" ") + 1);
//         game = retour.substr(0, retour.find(" "));
//         retour.erase(0, retour.find(" ") + 1);
//         user = retour.substr(0, retour.find(" "));
//     }
//     while (boolean == false) {
//         void *handle = openlib(lib.c_str());
//         if (!handle)
//             return;
//         creator create = (creator) dlsym(handle, "create");
//         IDisplay *cr = create();
//         void *game_ = openlib(game.c_str());
//         if (!game_)
//             return;
//         jeu_menu jeu = (jeu_menu) dlsym(game_, "create");
//         IGame *j = jeu(cr);
//         boolean = j->quit();
//         std::string retour = j->finish();
//         if (retour.length() > 0) {
//             lib = retour.substr(0, retour.find(" "));
//             retour.erase(0, retour.find(" ") + 1);
//             game = retour.substr(0, retour.find(" "));
//             retour.erase(0, retour.find(" ") + 1);
//             user = retour.substr(0, retour.find(" "));
//         }
//     }
// }

// text::text (std::string name, std::string str, int x, int y, std::string color) : name(name), str(str), x(x), y(y), color(color)
// {
// }

// image::image (std::string name, std::string path, int x, int y, char chara, std::string color) : name(name), path(path), x(x), y(y), chara(chara), color(color)
// {
// }