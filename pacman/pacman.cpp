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
    int i = 0, n = 0;
    std::ifstream file(filename); // Ouverture du fichier en mode lecture
    std::string buff;
    if (file.is_open()) {
        while (getline(file, buff)) { // Lecture de chaque ligne du fichier
            std::string name = "map_" + std::to_string(i);
            // (*textt).push_back(text(name, buff, 0, i,"blue"));
            for (; n < buff.size(); n++) {
                if (buff[n] == '*' || buff[n] == '-') {
                    (*sprite).push_back(image("map_" + std::to_string(i) + std::to_string(n), "SFML/pacou.png", n, i, buff[n], "blue", 0));
                } else
                    (*sprite).push_back(image("map_" + std::to_string(i) + std::to_string(n), "SFML/empty.png", n, i, buff[n], "white", 0));
            }
            map.insert(std::pair<std::string, std::string>(name, buff));
            i++, n=0;
        }
        file.close(); // Fermeture du fichier
    }
    (*sprite).push_back(image("pacman", "SFML/pacman.png", pos_pacman_x, pos_pacman_y, 'C', "yellow", 0));
    (*sprite).push_back(image("ghost1", "SFML/red.png", 25, 9, 'A', "red", 0));
    (*sprite).push_back(image("ghost2", "SFML/orange.png", 25, 11, 'A', "yellow", 0));
    (*sprite).push_back(image("ghost3", "SFML/blue.png", 27, 9, 'A', "blue", 0));
    (*sprite).push_back(image("ghost4", "SFML/pink.png", 27, 11, 'A', "pink", 0));
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
    if (input == 259 && map["map_" + std::to_string(pos_pacman_y - 1)].at(pos_pacman_x) == ' ') {
        direction = 'b';
    }
    if (input == 258 && map["map_" + std::to_string(pos_pacman_y + 1)].at(pos_pacman_x) == ' ') {
        direction = 'h';
    }
    if (input == 260 && map["map_" + std::to_string(pos_pacman_y)].at(pos_pacman_x - 1) == ' ') {
        direction = 'g';
    }
    if (input == 261 && map["map_" + std::to_string(pos_pacman_y)].at(pos_pacman_x + 1) == ' ') {
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
    if (direction == 'h' && map["map_" + std::to_string(pos_pacman_y + 1)].at(pos_pacman_x) == ' ') {
        pos_pacman_y += 1;
    }
    if (direction == 'b' && map["map_" + std::to_string(pos_pacman_y - 1)].at(pos_pacman_x) == ' ') {
        pos_pacman_y -= 1;
    }
    if (direction == 'g' && map["map_" + std::to_string(pos_pacman_y)].at(pos_pacman_x - 1) == ' ') {
        pos_pacman_x -= 1;
    }
    if (direction == 'd' && map["map_" + std::to_string(pos_pacman_y)].at(pos_pacman_x + 1) == ' ') {
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