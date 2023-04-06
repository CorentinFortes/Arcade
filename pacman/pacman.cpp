/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** pacman.cpp
*/

#include "pacman.hpp"

void pacman::init(std::vector <image> *sprite, std::vector <text> *textt)
{
    std::string filename = "pacman/pacman.txt";
    int i = 0;
    std::ifstream file(filename); // Ouverture du fichier en mode lecture
    std::string buff;
    if (file.is_open()) {
        while (getline(file, buff)) { // Lecture de chaque ligne du fichier
            std::string name = "map_" + std::to_string(i);
            (*textt).push_back(text(name, buff, 0, i,"blue"));
            i++;
        }
        file.close(); // Fermeture du fichier
    }
    (*sprite).push_back(image("pacman", "", pos_pacman_x, pos_pacman_y, 'C', "yellow"));
    (*sprite).push_back(image("ghost1", "", 25, 9, 'A', "red"));
    (*sprite).push_back(image("ghost2", "", 25, 11, 'A', "yellow"));
    (*sprite).push_back(image("ghost3", "", 27, 9, 'A', "blue"));
    (*sprite).push_back(image("ghost4", "", 27, 11, 'A', "pink"));
}

std::string pacman::input(int input, std::vector <image> *sprite, std::vector <text> *textt, int *i)
{
    if (input == 1) {
        isQuit = true;
        return "";
    }
    if (input == 9) {
        *i = 1;
    }
    if (input == 259 && textt->at(findText("map_" + std::to_string(pos_pacman_y - 1), textt)).str[pos_pacman_x] == ' ') {
        direction = 'b';
    }
    if (input == 258 && textt->at(findText("map_" + std::to_string(pos_pacman_y + 1), textt)).str[pos_pacman_x] == ' ') {
        direction = 'h';
    }
    if (input == 260 && textt->at(findText("map_" + std::to_string(pos_pacman_y), textt)).str[pos_pacman_x - 1] == ' ') {
        direction = 'g';
    }
    if (input == 261 && textt->at(findText("map_" + std::to_string(pos_pacman_y), textt)).str[pos_pacman_x + 1] == ' ') {
        direction = 'd';
    }
    return "";
}

void pacman::play(std::vector <image> *sprite, std::vector <text> *textt)
{
    if (isQuit == true)
        retour = "";
    if (pos_pacman_x == 0 || pos_pacman_x == 65 || pos_pacman_y == 0 || pos_pacman_y == 21) {
        isQuit = true;
        retour = "";
    }
    if (direction == 'h' && textt->at(findText("map_" + std::to_string(pos_pacman_y + 1), textt)).str[pos_pacman_x] == ' ') {
        pos_pacman_y += 1;
    }
    if (direction == 'b' && textt->at(findText("map_" + std::to_string(pos_pacman_y - 1), textt)).str[pos_pacman_x] == ' ') {
        pos_pacman_y -= 1;
    }
    if (direction == 'g' && textt->at(findText("map_" + std::to_string(pos_pacman_y), textt)).str[pos_pacman_x - 1] == ' ') {
        pos_pacman_x -= 1;
    }
    if (direction == 'd' && textt->at(findText("map_" + std::to_string(pos_pacman_y), textt)).str[pos_pacman_x + 1] == ' ') {
        pos_pacman_x += 1;
    }
    sprite->at(findImage("pacman", sprite)).x = pos_pacman_x;
    sprite->at(findImage("pacman", sprite)).y = pos_pacman_y;
}

bool pacman::quit()
{
    return isQuit;
}

std::string pacman::finish()
{
    return retour;
}

pacman::pacman(/* args */) : isQuit(false), pos_pacman_x(25), pos_pacman_y(7), direction('d')
{
}

pacman::~pacman()
{
}

extern "C" pacman* create()
{
    return new pacman();
}

extern "C" bool islib()
{
    return false;
}