/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** func.cpp
*/

#include "ncurse.hpp"

void Display::printHello(void)
{
    std::cout << "ncurse world" << std::endl;
}

void Display::printMenu(std::vector <std::string> menu, std::vector <std::string> games)
{
    mvprintw(0, 0, "Choose a lib :");
    mvprintw(1, 0, menu[0].c_str());
    mvprintw(2, 0, menu[1].c_str());
    mvprintw(3, 0, menu[2].c_str());
    mvprintw(4, 0, "\n");
    mvprintw(5, 0, "Choose a game :");
    mvprintw(6, 0, games[0].c_str());
    mvprintw(7, 0, games[1].c_str());
    mvprintw(8, 0, games[2].c_str());
    mvprintw(9, 0, games[3].c_str());
    mvprintw(10, 0, games[4].c_str());
    mvprintw(11, 0, games[5].c_str());
    mvprintw(12, 0, games[6].c_str());
    mvprintw(13, 0, "\n");
    mvprintw(14, 0, "User : ");
}

std::string Display::printUser()
{
    std::string user;
    while (1) {
        int ch = getch();
        if (ch == 27 || ch == 10) {
            return(user);
        }
        if (ch >= 97 && ch <= 122)
            user += ch;
        if (ch >= 65 && ch <= 90)
            user += ch;
        if (ch == 263) {
            if (user.size() > 0)
                user.pop_back();
            mvprintw(14, 7 + user.size(), " ");
        }
        mvprintw(14, 7, user.c_str());
        refresh();
    }
}

std::string Display::createMenu(void)
{
    WINDOW *window = initscr();
    keypad(window, TRUE);
    noecho();
    start_color();
    std::string retour;
    std::vector <std::string> menu = {"./lib/arcade_ncurses.so", "./lib/arcade_sdl.so", "./lib/arcade_sfml.so"};
    std::vector <std::string> games = {"./lib/arcade_centipede.so", "./lib/arcade_menu.so", "./lib/nibbler.so",
    "./lib/arcade_pacman.so", "./lib/arcade_qix.so", "./lib/arcade_snake.so" , "./lib/arcade_solarfox.so"};
    curs_set(0);
    int selectgame = -1, selectlib = -1, surligne = 1;
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    while (1) {
        printMenu(menu, games);
        attron(COLOR_PAIR(1));
        if (surligne < 4)
            mvprintw(surligne, 0, menu[surligne - 1].c_str());
        if (surligne > 5)
            mvprintw(surligne, 0, games[surligne - 6].c_str());
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        if (selectlib != -1)
            mvprintw(selectlib, 0, menu[selectlib - 1].c_str());
        if (selectgame != -1)
            mvprintw(selectgame, 0, games[selectgame - 6].c_str());
        attroff(COLOR_PAIR(2));
        int ch = getch();
        if (ch == 27)
            break;
        if (ch == 10) {
            if (surligne < 4)
                selectlib = surligne;
            if (surligne > 5)
                selectgame = surligne;
            if (selectlib != -1 && selectgame != -1) {
                retour += printUser();
                endwin();
                std::cout << games[selectgame - 6] << " " << menu[selectlib - 1] << " " << retour << std::endl;
                return (games[selectgame - 6] + " " + menu[selectlib - 1] + " " + retour);
            }
        }
        if (ch == KEY_UP) {
            if (surligne == 6)
                surligne = 3;
            else if (surligne > 1)
                surligne--;
        }
        if (ch == KEY_DOWN) {
            if (surligne == 3)
                surligne = 6;
            else if (surligne < 12)
                surligne++;
        }
        refresh();
    }
    endwin();
    return "close";
}

extern "C" IDisplay* create(void)
{
    return new Display();
}