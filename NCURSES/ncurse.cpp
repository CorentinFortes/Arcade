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
    nodelay(stdscr, TRUE);
    curs_set(0);
}

void Display::createText(std::string name, std::string str, int x, int y)
{
    texts.insert(std::map<std::string, std::string>::value_type(name, str));
}

void Display::drawText(std::string key, int x, int y)
{
    mvprintw(y, x, texts[key].c_str());
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

void Display::changeColor(std::string str, int x, int y, std::string color)
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
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
    mvprintw(y, x, str.c_str());
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
    attroff(COLOR_PAIR(5));
}

void Display::modifieText(std::string key, int x, int y, std::string newStr)
{
    for (int i = 0; i < texts[key].size(); i++) {
        mvprintw(y, x + i, " ");
    }
    texts[key] = newStr;
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

void Display::createImage(std::string name, std::string path, int x, int y, char chara, int rotate)
{
    images.insert(std::map<std::string, char>::value_type(name, chara));
}

void Display::drawImage(std::string key, int x, int y, std::string color, char c, int rotate)
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
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
    if (color == "pink")
        attron(COLOR_PAIR(6));
    char str[] = {c, '\0'};
    mvprintw(y, x, str);
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
    attroff(COLOR_PAIR(5));
    attroff(COLOR_PAIR(6));
}

void Display::createTexts(std::vector <text> text)
{
    for (int i = 0; i < text.size(); i++) {
        createText(text[i].name, text[i].str, text[i].x, text[i].y);
    }
}

void Display::createSprites(std::vector <image> image)
{
    for (int i = 0; i < image.size(); i++) {
        createImage(image[i].name, image[i].path, image[i].x, image[i].y, image[i].chara, image[i].rotate);
    }
}

void Display::drawSprites(std::vector <image> image)
{
    // if (image.size() != images.size()) {
    //     images.insert(std::map<std::string, char>::value_type(image.at(image.size() - 1).name, image.at(image.size() - 1).chara));

    // }
    for (int i = 0; i < image.size(); i++) {
        // if (images[image[i].name] != image[i].chara)
        //     images[image[i].name] = image[i].chara;
        drawImage(image[i].name, image[i].x, image[i].y, image[i].color, image[i].chara, image[i].rotate);
    }
}

void Display::drawTexts(std::vector <text> text)
{
    for (int i = 0; i < text.size(); i++) {
        changeColor(text[i].str, text[i].x, text[i].y, text[i].color);
    }
}

// std::string Display::changeLib()
// {
//     endwin();
//     std::string str = "lib/sdl2.so";
// }

extern "C" IDisplay* create(void)
{
    return new Display();
}

extern "C" bool islib()
{
    return true;
}