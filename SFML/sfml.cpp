/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** func.cpp
*/

#include "Display.hpp"

void Display::openWindow()
{
    window.create(sf::VideoMode(1900, 800), "SFML menu");
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
    if (y != 0)
        y = y * 35;
    textSfml[name] = Text(str,x,y);
}

void Display::createTexts(std::vector <text> text)
{
    for (int i = 0; i < text.size(); i++) {
        createText(text.at(i).name, text.at(i).str, text.at(i).x, text.at(i).y);
    }
}

void Display::createImage(std::string name, std::string path, int x, int y, char chara, int rotate)
{
    spriteSfml[name] = Sprites(path, x, y);
    sf::FloatRect bounds = spriteSfml[name].sprite.getLocalBounds();
    spriteSfml[name].sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    spriteSfml[name].sprite.setScale(1.25, 1.25);
}

void Display::createSprites(std::vector <image> sprite)
{
    for (int i = 0; i < sprite.size(); i++) {
        createImage(sprite.at(i).name, sprite.at(i).path, sprite.at(i).x, sprite.at(i).y, sprite.at(i).chara, sprite.at(i).rotate);
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
    if (spriteSfml.size() < sprite.size()) {
        createSprites(sprite);
    }
    for (int i = 0; i < sprite.size(); i++) {
        spriteSfml[sprite.at(i).name].sprite.setRotation(sprite.at(i).rotate);
        spriteSfml[sprite.at(i).name].sprite.setPosition(sprite.at(i).x * 30, sprite.at(i).y * 40);
        sf::Texture texture;
        texture.loadFromFile(sprite.at(i).path);
        spriteSfml[sprite.at(i).name].sprite.setTexture(texture);
        sf::FloatRect bounds = spriteSfml[sprite.at(i).name].sprite.getLocalBounds();
        spriteSfml[sprite.at(i).name].sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
        window.draw(spriteSfml[sprite.at(i).name].sprite);
    }
}

int Display::event()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            return 1;
        } if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
            return 1;
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
            return 2;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
            return 259;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down) {
            return 258;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left) {
            return 260;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right) {
            return 261;
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