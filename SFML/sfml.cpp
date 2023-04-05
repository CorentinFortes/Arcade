/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** func.cpp
*/

#include "Display.hpp"

void Display::openWindow()
{
    window.create(sf::VideoMode(900, 800), "SFML menu");
}

void Display::closeWindow()
{
    window.close();
}

void Display::displayWindow()
{
    window.display();
    window.clear();
}

void Display::createText(std::string name, std::string str, int x, int y)
{
    x = x + 10;
    y = y * 35;
    textSfml[name] = Text(str,x,y);
}

void Display::createTexts(std::vector <text> text)
{
    for (int i = 0; i < text.size(); i++) {
        createText(text.at(i).name, text.at(i).str, text.at(i).x, text.at(i).y);
    }
}

void Display::createImage(std::string name, std::string path, int x, int y, char chara)
{
    spriteSfml[name] = sf::Sprite();
    sf::Texture texture;
    texture.loadFromFile(path);
    spriteSfml[name].setTexture(texture);
    spriteSfml[name].setPosition(x, y);
}

void Display::createSprites(std::vector <image> sprite)
{
    for (int i = 0; i < sprite.size(); i++) {
        createImage(sprite.at(i).name, sprite.at(i).path, sprite.at(i).x, sprite.at(i).y, sprite.at(i).chara);
    }
}

void Display::setNeWColor(std::string color, Text &text)
{
    if (color == "red")
        text.txt.setFillColor(sf::Color::Red);
    if (color == "green")
        text.txt.setFillColor(sf::Color::Green);
    if (color == "blue")
        text.txt.setFillColor(sf::Color::Blue);
    if (color == "white")
        text.txt.setFillColor(sf::Color::White);
    if (color == "yellow")
        text.txt.setFillColor(sf::Color::Yellow);
    if (color == "black")
        text.txt.setFillColor(sf::Color::Black);
}

void Display::drawTexts(std::vector <text> text)
{
    for (int i = 0; i < text.size(); i++) {
        setNeWColor(text.at(i).color, textSfml[text.at(i).name]);
        modifieText(text.at(i).name, text.at(i).x, text.at(i).y, text.at(i).str);
        window.draw(textSfml[text.at(i).name].txt);
    }
}

void Display::drawSprites(std::vector <image> sprite)
{
    for (auto &i : spriteSfml) {
        window.draw(i.second);
    }
}

int Display::event()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            return 1;
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            // std::cout << "enter" << std::endl;
            return 2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            // std::cout << "up" << std::endl;
            return 259;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            // std::cout << "down" << std::endl;
            return 258;
        }
        if (event.type == sf::Event::TextEntered)
            return event.text.unicode;
    }
    return -1;
}
 
void Display::changeColor(std::string key, int x, int y, std::string color)
{
    if (color == "red")
        textSfml[key].txt.setFillColor(sf::Color::Red);
    if (color == "green")
        textSfml[key].txt.setFillColor(sf::Color::Green);
    if (color == "blue")
        textSfml[key].txt.setFillColor(sf::Color::Blue);
    if (color == "white")
        textSfml[key].txt.setFillColor(sf::Color::White);
    if (color == "yellow")
        textSfml[key].txt.setFillColor(sf::Color::Yellow);
    if (color == "black")
        textSfml[key].txt.setFillColor(sf::Color::Black);
}

void Display::modifieText(std::string key, int x, int y, std::string newStr)
{
    // window.clear();
    textSfml[key].txt.setPosition(x + 10, y * 35);
    if (key == "user")
        textSfml[key].txt.setPosition(x + 100, y * 35);
    textSfml[key].txt.setString(newStr);
}

extern "C" IDisplay* create(void)
{
    return new Display();
}

extern "C" bool islib()
{
    return true;
}