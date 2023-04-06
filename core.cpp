/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** core.cpp
*/

#include "core.hpp"
#include <dirent.h>

void Core::openLibs(std::string libr, std::string gamee, std::string user)
{
    void *handle = openlib(libr.c_str());
    if (!handle)
        return;
    create = (creator) dlsym(handle, "create");
    display = create();
    void *game_ = openlib(gamee.c_str());
    if (!game_)
        return;
    jeu_menu jeu = (jeu_menu) dlsym(game_, "create");
    game = jeu();
}

std::string Core::changelib(std::string *lib)
{
    DIR* dir = opendir("lib");
    std::vector <std::string> libs;
    struct dirent* doss;
    while ((doss = readdir(dir)) != nullptr) {
        if (doss->d_type == DT_REG) {
            std::string filename(doss->d_name);
            if (filename.length() >= 3 && filename.substr(filename.length() - 3) == ".so") {
                void *handle = openlib("lib/" + filename);
                if (!handle)
                    return "";
                typelib libt = (typelib) dlsym(handle, "islib");
                if (libt()) {
                    libs.push_back("lib/" + filename);
                }
                dlclose(handle);
            }
        }
    }
    closedir(dir);
    for (int i = 0; i < libs.size(); i++) {
        if (libs[i] == *lib) {
            if (i + 1 == libs.size()) {
                (*lib) = libs[0];
                return (libs[0]);
            } else {
                (*lib) = libs[i + 1];
                return (libs[i + 1]);
            }
        }
    }
    return "";
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
    int swap = 0;
    while (game->quit() == false) {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        display->drawTexts(text);
        display->drawSprites(sprite);
        retour = game->input(display->event(), &sprite, &text, &swap);
        if (swap == 1) {
            void *handle = openlib(changelib(&lib).c_str());
            if (!handle)
                return;
            create = (creator) dlsym(handle, "create");
            display->closeWindow();
            display = create();
            display->openWindow();
            display->createTexts(text);
            display->createSprites(sprite);
            swap = 0;
        }
        game->play(&sprite, &text);
        display->displayWindow(); 
    }
    if (retour != "") {
        user = retour.substr(0, retour.find(" "));
        retour.erase(0, retour.find(" ") + 1);
        lib = retour.substr(0, retour.find(" "));
        retour.erase(0, retour.find(" ") + 1);
        gamee = retour.substr(0, retour.find(" "));
        display->closeWindow();
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