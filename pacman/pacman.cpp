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
    ghost1.x = 25;
    ghost1.y = 9;
    ghost2.x = 25;
    ghost2.y = 11;
    ghost3.x = 27;
    ghost3.y = 9;
    ghost4.x = 27;
    ghost4.y = 11;
    ghost1.direction = 'h';
    ghost2.direction = 'h';
    ghost3.direction = 'h';
    ghost4.direction = 'h';
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
    ghost1 = decideNextDestination(ghost1);
    // ghost2 = decideNextDestination(ghost2);
    // ghost3 = decideNextDestination(ghost3);
    // ghost4 = decideNextDestination(ghost4);
    // if (map["map_" + std::to_string(ghost1.y)].at(ghost1.x) == ' ') {
    sprite->at(findImage("ghost1", sprite)).x = ghost1.x;
    sprite->at(findImage("ghost1", sprite)).y = ghost1.y;
    if (ghost1.x == pos_pacman_x && ghost1.y == pos_pacman_y) {
        isQuit = true;
        retour = "";
    }
}

ghost pacman::decideNextDestination(ghost g) {
    int i = 1;
    int best_x, best_y;
    if (abs(g.x - pos_pacman_x) + abs(g.y - pos_pacman_y) < 15) {
        if (abs(g.x + 1 - pos_pacman_x) < abs(g.x - 1 - pos_pacman_x))
            best_x = 1;
        else if (abs(g.x + 1 - pos_pacman_x) > abs(g.x - 1 - pos_pacman_x))
            best_x = -1;
        else
            best_x = 0;
        if (abs(g.y + 1 - pos_pacman_y) < abs(g.y - 1 - pos_pacman_y))
            best_y = 1;
        else if (abs(g.y + 1 - pos_pacman_y) > abs(g.y - 1 - pos_pacman_y))
            best_y = -1;
        else
            best_y = 0;
        if (map["map_" + std::to_string(g.y + best_y)].at(g.x) != '*' && best_y != 0) {
            g.y += best_y;
            return g;
        } else if (map["map_" + std::to_string(g.y)].at(g.x + best_x) != '*' && best_x != 0) {
            g.x += best_x;
            return g;
        }
    }
    return g;
}

bool pacman::quit()
{
    return isQuit;
}

std::string pacman::finish()
{
    return retour;
}

pacman::pacman(/* args */) : isQuit(false), pos_pacman_x(35), pos_pacman_y(13), direction('d')
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