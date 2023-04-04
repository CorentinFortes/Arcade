/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** menu.cpp
*/

#include "menu.hpp"

typedef bool* (*typelib) ();

void *openlib(std::string path)
{
    void *handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return NULL;
    }
    return handle;
}

void menu::init(std::vector <image> *sprite, std::vector <text> *texts)
{
    isQuit = false;
    DIR* dir = opendir("./lib");
    struct dirent* doss;
    while ((doss = readdir(dir)) != nullptr) {
        if (doss->d_type == DT_REG) {
            std::string filename(doss->d_name);
            if (filename.length() >= 3 && filename.substr(filename.length() - 3) == ".so") {
                void *handle = openlib("./lib/" + filename);
                if (!handle)
                    return;
                typelib libt = (typelib) dlsym(handle, "islib");
                if (libt()) {
                    libs.push_back("./lib/" + filename);
                } else {
                    games.push_back("./lib/" + filename);
                }
                dlclose(handle);
            }
        }
    }
    closedir(dir);
    // int empty = 0;
    // menu->openWindow();
    (*texts).push_back(text("Choose a lib :", "Choose a lib :", 0, 0, "white"));
    // menu->createText("Choose a lib :", "Choose a lib :", 0, 0);
    for (; max_lib < 3; max_lib++) {
        if (libs.size() > max_lib) {
            (*texts).push_back(text(libs[max_lib], libs[max_lib], 0, max_lib + 1, "white"));
            // menu->createText(libs[max_lib], libs[max_lib], 0, max_lib + 1);
        }
    }
    (*texts).push_back(text("\n 1", "\n", 0, max_lib + 1, "white"));
    (*texts).push_back(text("Choose a game :", "Choose a game :", 0, max_lib + 2, "white"));
    // menu->createText("\n 1", "\n", 0, max_lib + 1);
    // menu->createText("Choose a game :", "Choose a game :", 0, max_lib + 2);
    max_tot = max_lib + 2;
    for (; max_game < 3; max_game++) {
        if (games.size() > max_game) {
            (*texts).push_back(text(games[max_game], games[max_game], 0, max_tot + 1, "white"));
            // menu->createText(games[max_game], games[max_game], 0, max_tot + 1);
            max_tot++;
        }
    }
    (*texts).push_back(text("\n 2", "\n", 0, max_tot + 1, "white"));
    (*texts).push_back(text("User : ", "User : ", 0, max_tot + 2, "white"));
    (*texts).push_back(text("user", user, 7, max_tot + 2, "white"));
    // menu->createText("user", user, 100, max_tot + 2);
    // menu->createText("\n 2", "\n", 0, max_tot + 1);
    // menu->createText("User : ", "User : ", 0, max_tot + 2);
}

std::string menu::input(int ch, std::vector <image> *sprite, std::vector <text> *textt)
{
    if (isSelected == false) {
        if (ch == 9) {
            // menu->changeLib();
        }
        if (ch == 2) {
            if (surligne < max_lib + 2) {
                if (selectlib != -1)
                    textt->at(findText(libs[selectlib - 1], textt)).color = "white";
                    // menu->changeColor(libs[selectlib - 1], 0, selectlib, "white");
                selectlib = surligne;
            }
            if (surligne > max_lib + 2) {
                if (selectgame != -1)
                    textt->at(findText(games[selectgame - max_lib - 3], textt)).color = "white";
                    // menu->changeColor(games[selectgame - max_lib - 3], 0, selectgame, "white");
                selectgame = surligne;
            }
            if (selectlib != -1 && selectgame != -1) {
                // username += printUser(menu, libs, games, selectlib, selectgame);
                // if (username.empty() == false) {
                //     retour = retour + libs[selectlib - 1] + " " + games[selectgame - max_lib - 3] + " " + username;
                //     // menu->closeWindow();
                //     isQuit = true;
                //     return;
                //     // break;
                // }
                isSelected = true;
                // break;
            }
        }
        if (ch == 1) {
            // menu->closeWindow();
            isQuit = true;
            return "";
            // break;
        }
        if (ch == 259 && surligne > 2) {
            if (surligne == max_lib + 4) {
                // textt->at(findText(libs[max_lib - 1], textt)).color = "yellow";
                // menu->changeColor(games[0], 0, max_lib + 3, "white");
                surligne = max_lib + 1;
            } else {
                // if (surligne < max_lib + 1)
                //     textt->at(findText(libs[surligne - 1], textt)).color = "yellow";
                //     // menu->changeColor(libs[surligne - 1], 0, surligne, "white");
                // else if (surligne > max_lib + 2)
                //     textt->at(findText(games[surligne - max_lib - 3], textt)).color = "yellow";
                    // menu->changeColor(games[surligne - max_lib - 3], 0, surligne, "white");
                surligne--;
            }
        }
        if (ch == 258 && surligne < max_tot + 1) {
            if (surligne == max_lib + 1) {
                // textt->at(findText(libs[max_lib - 1], textt)).color = "yellow";
                // menu->changeColor(libs[max_lib - 1], 0, max_lib + 1, "white");
                surligne = max_lib + 4;
            } else {
                // if (surligne < max_lib + 1) {
                //     textt->at(findText(libs[surligne - 1], textt)).color = "yellow";
                //     // if ((surligne - 2) > 0)
                //     //     textt->at(findText(libs[surligne - 2], textt)).color = "white";
                //     // menu->changeColor(libs[surligne - 1], 0, surligne, "white");
                // } else if (surligne > max_lib + 2) {
                //     textt->at(findText(games[surligne - max_lib - 3], textt)).color = "yellow";
                    // if ((surligne - max_lib - 4) > 0)
                    //     textt->at(findText(libs[surligne - 2], textt)).color = "white";
                    // menu->changeColor(games[surligne - max_lib - 3], 0, surligne, "white");
                // }
                surligne++;
            }
        }
    } else {
        // textt->at(findText("user", textt)).str = "test";
        if (ch >= 97 && ch <= 122) {
            textt->at(findText("user", textt)).str += ch;
        }
        if (ch >= 65 && ch <= 90) {
            textt->at(findText("user", textt)).str += ch;
        }
        if ((ch == 263 || ch == 8)) {
            textt->at(findText("user", textt)).str.pop_back();
        }
        user = textt->at(findText("user", textt)).str;
        if ((ch == 1 || ch == 2) && user != "") {
            isQuit = true;
            user += " " + libs[selectlib - 2] + " " + games[selectgame - max_lib - 4];            
            return user;
        }
    }
    return "";
}

void menu::play(std::vector <image> *sprite, std::vector <text> *textt)
{
    for (int i = 0; i < textt->size(); i++) {
        if (textt->at(i).color != "red")
            textt->at(i).color = "white";
    }
    if (selectgame != -1) {
        textt->at(selectgame - 1).color = "red";
    }
    if (selectlib != -1) {
        textt->at(selectlib - 1).color = "red";
    }
    textt->at(surligne - 1).color = "yellow";
}


// std::string menu::printUser(IDisplay *menu, std::vector <std::string> libs, std::vector <std::string> games, int selectlib, int selectgame)
// {
//     std::string user;
//     menu->createText("user", user, 100, max_tot + 2);
//     int empty = 0;
//     while (1) {
//         menu->modifieText("user", 7, max_tot + 2, user);
//         menu->drawText("Choose a lib :", 0, 0);
//         for (int i = 0; i < max_lib; i++) {
//             menu->drawText(libs[i], 0, i + 1);
//         }
//         menu->drawText("\n 1", 0, max_lib + 1);
//         menu->drawText("Choose a game :", 0, max_lib + 2);
//         for (int i = 0; i < max_game - 1; i++) {
//             menu->drawText(games[i], 0, max_lib + 3 + i);
//         }
//         menu->drawText("\n 2", 0, max_tot + 1);
//         menu->drawText("User : ", 0, max_tot + 2);
//         if (user.length() > 0)
//             menu->drawText("user", 7, max_tot + 2);
//         if (selectlib != -1)
//             menu->changeColor(libs[selectlib - 1], 0, selectlib, "yellow");
//         if (selectgame != -1)
//             menu->changeColor(games[selectgame - max_lib - 3], 0, selectgame, "yellow");
//         int ch = menu->event();
//         if ((ch == 1 || ch == 2) && empty == 1) {
//             return(user);
//         }
//         if (ch >= 97 && ch <= 122) {
//             user += ch;
//             empty = 1;
//         } if (ch >= 65 && ch <= 90) {
//             user += ch;
//             empty = 1;
//         } if ((ch == 263 || ch == 8)) {
//             if (user.size() == 0) {
//                 empty = 0;
//             }
//             if (user.size() > 0)
//                 user.pop_back();
//         }
//         if (user.length() > 0)
//             menu->drawText("user", 7, max_tot + 2);
//         menu->displayWindow();
//     }
// }

// menu::menu(IDisplay *menu)
// {
//     isQuit = false;
//     std::vector <std::string> games;
//     std::vector <std::string> libs;
//     DIR* dir = opendir("./lib");
//     struct dirent* doss;
//     while ((doss = readdir(dir)) != nullptr) {
//         if (doss->d_type == DT_REG) {
//             std::string filename(doss->d_name);
//             if (filename.length() >= 3 && filename.substr(filename.length() - 3) == ".so") {
//                 void *handle = openlib("./lib/" + filename);
//                 if (!handle)
//                     return;
//                 typelib libt = (typelib) dlsym(handle, "islib");
//                 if (libt()) {
//                     libs.push_back("./lib/" + filename);
//                 } else {
//                     games.push_back("./lib/" + filename);
//                 }
//                 dlclose(handle);
//             }
//         }
//     }
//     closedir(dir);
//     std::string user;
//     int empty = 0;
//     menu->openWindow();
//     menu->createText("Choose a lib :", "Choose a lib :", 0, 0);
//     for (; max_lib < 3; max_lib++) {
//         if (libs.size() > max_lib) {
//             menu->createText(libs[max_lib], libs[max_lib], 0, max_lib + 1);
//         }
//     }
//     menu->createText("\n 1", "\n", 0, max_lib + 1);
//     menu->createText("Choose a game :", "Choose a game :", 0, max_lib + 2);
//     max_tot = max_lib + 2;
//     for (; max_game < 3; max_game++) {
//         if (games.size() > max_game) {
//             menu->createText(games[max_game], games[max_game], 0, max_tot + 1);
//         }
//         max_tot++;
//     }
//     menu->createText("user", user, 100, max_tot + 2);
//     menu->createText("\n 2", "\n", 0, max_tot + 1);
//     menu->createText("User : ", "User : ", 0, max_tot + 2);
//     while (1) {
//         menu->drawText("Choose a lib :", 0, 0);
//         for (int i = 0; i < max_lib; i++) {
//             menu->drawText(libs[i], 0, i + 1);
//         }
//         menu->drawText("\n 1", 0, max_lib + 1);
//         menu->drawText("Choose a game :", 0, max_lib + 2);
//         for (int i = 0; i < max_game - 1; i++) {
//             menu->drawText(games[i], 0, max_lib + 3 + i);
//         }
//         menu->drawText("\n 2", 0, max_tot + 1);
//         menu->drawText("User : ", 0, max_tot + 2);
//         if (surligne != -1) {
//             if (surligne < max_lib + 1)
//                 menu->changeColor(libs[surligne - 1], 0, surligne, "red");
//             if (surligne > max_lib + 2)
//                 menu->changeColor(games[surligne - max_lib - 3], 0, surligne, "red");
//         }
//         if (selectlib != -1)
//             menu->changeColor(libs[selectlib - 1], 0, selectlib, "yellow");
//         if (selectgame != -1)
//             menu->changeColor(games[selectgame - max_lib - 3], 0, selectgame, "yellow");

//         int ch = menu->event();
//         if (ch == 9) {
//             // menu->changeLib();
//         }
//         if (ch == 2) {
//             if (surligne < max_lib + 1) {
//                 if (selectlib != -1)
//                     menu->changeColor(libs[selectlib - 1], 0, selectlib, "white");
//                 selectlib = surligne;
//             }
//             if (surligne > max_lib + 2) {
//                 if (selectgame != -1)
//                     menu->changeColor(games[selectgame - max_lib - 3], 0, selectgame, "white");
//                 selectgame = surligne;
//             }
//             if (selectlib != -1 && selectgame != -1) {
//                 username += printUser(menu, libs, games, selectlib, selectgame);
//                 if (username.empty() == false) {
//                     retour = retour + libs[selectlib - 1] + " " + games[selectgame - max_lib - 3] + " " + username;
//                     menu->closeWindow();
//                     break;
//                 }
//                 break;
//             }
//         }
//         if (ch == 1) {
//             menu->closeWindow();
//             isQuit = true;
//             break;
//         }
//         if (ch == 259 && surligne > 1) {
//             if (surligne == max_lib + 3) {
//                 menu->changeColor(games[0], 0, max_lib + 3, "white");
//                 surligne = max_lib;
//             } else {
//                 if (surligne < max_lib + 1)
//                     menu->changeColor(libs[surligne - 1], 0, surligne, "white");
//                 if (surligne > max_lib + 2)
//                     menu->changeColor(games[surligne - max_lib - 3], 0, surligne, "white");
//                 surligne--;
//             }
//         }
//         if (ch == 258 && surligne < max_tot - 1) {
//             if (surligne == max_lib) {
//                 menu->changeColor(libs[max_lib - 1], 0, max_lib + 1, "white");
//                 surligne = max_lib + 3;
//             } else {
//                 if (surligne < max_lib + 1)
//                     menu->changeColor(libs[surligne - 1], 0, surligne, "white");
//                 if (surligne > max_lib + 2)
//                     menu->changeColor(games[surligne - max_lib - 3], 0, surligne, "white");
//                 surligne++;
//             }
//         }
//         menu->displayWindow();
//     }
// }

bool menu::quit()
{
    return isQuit;
}

std::string menu::finish()
{
    return retour;
}

extern "C" menu* create()
{
    return new menu();
}

extern "C" bool islib()
{
    return false;
}