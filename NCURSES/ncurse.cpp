// /*
// ** EPITECH PROJECT, 2022
// ** B-OOP-400-MAR-4-1-arcade-corentin.fortes
// ** File description:
// ** func.cpp
// */

#include "ncurse.hpp"

void Display::openWindow()
{
    window = initscr();
    keypad(window, TRUE);
    noecho();
    start_color();
    curs_set(0);
}

void Display::createText(std::string name, std::string str, int x, int y)
{
    text.insert(std::map<std::string, std::string>::value_type(name, str));
}

void Display::drawText(std::string key, int x, int y)
{
    mvprintw(y, x, text[key].c_str());
}

int Display::event()
{
    int ch = getch();
    if (ch == 27)
        return (1);
    if (ch == 10)
        return (2);
    return (ch);
}

void Display::changeColor(std::string key, int x, int y, std::string color)
{
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    if (color == "red")
        attron(COLOR_PAIR(1));
    if (color == "green")
        attron(COLOR_PAIR(2));
    if (color == "blue")
        attron(COLOR_PAIR(3));
    if (color == "yellow")
        attron(COLOR_PAIR(4));
    if (color == "white")
        attron(COLOR_PAIR(5));
    mvprintw(y, x, text[key].c_str());
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
    attroff(COLOR_PAIR(5));
}

void Display::modifieText(std::string key, int x, int y, std::string newStr)
{
    for (int i = 0; i < text[key].size(); i++) {
        mvprintw(y, x + i, " ");
    }
    text[key] = newStr;
    mvprintw(y, x, newStr.c_str());
}

void Display::closeWindow()
{
    endwin();
}

void Display::displayWindow()
{
    refresh();
    clear();
}

void Display::createImage(std::string name, std::string path, int x, int y, char chara)
{
    image.insert(std::map<std::string, char>::value_type(name, chara));
}

void Display::drawImage(std::string key, int x, int y, std::string color)
{
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    if (color == "red")
        attron(COLOR_PAIR(1));
    if (color == "green")
        attron(COLOR_PAIR(2));
    if (color == "blue")
        attron(COLOR_PAIR(3));
    if (color == "yellow")
        attron(COLOR_PAIR(4));
    if (color == "white")
        attron(COLOR_PAIR(5));
    char str[1] = {image[key]};
    mvprintw(y, x, str);
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
    attroff(COLOR_PAIR(5));
}

extern "C" IDisplay* create(void)
{
    return new Display();
}