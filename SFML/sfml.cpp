// /*
// ** EPITECH PROJECT, 2022
// ** B-OOP-400-MAR-4-1-arcade-corentin.fortes
// ** File description:
// ** func.cpp
// */
// #include "Display.hpp"
// #include "Text.hpp"

// std::string Display::createMenu(void)
// {
//     sf::RenderWindow window(sf::VideoMode(800, 700), "SFML menu");
//     Text game_title("Game List :", 10, 0);
//     Text snake("./lib/arcade_snake.so", 50, 50);
//     snake.changeColor(sf::Color::Red);
//     Text pacman("./lib/arcade_pacman.so", 50, 100);
//     Text lib_title("Graphicals List :", 10, 250);
//     Text sfml("./lib/arcade_sfml.so", 50, 300);
//     sfml.changeColor(sf::Color::Red);
//     Text ncurses("./lib/arcade_ncurses.so", 50, 350);
//     Text sdl("./lib/arcade_sdl.so", 50, 400);
//     Text user("Username :", 10, 500);
//     Text name("", 20, 550);
//     int select = 0, enter = 0, pos = 50;
//     std::string path;
//     while (1) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//                 return path;
//             }
//             if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && select == 0) {
//                 if (pos == 50) {
//                     pos = 100;
//                     pacman.changeColor(sf::Color::Red);
//                     snake.changeColor(sf::Color::White);
//                 } else if (pos == 100) {
//                     pos = 50;
//                     snake.changeColor(sf::Color::Red);
//                     pacman.changeColor(sf::Color::White);
//                 }
//             }
//             if (select == 1 && event.key.code == sf::Keyboard::Return)
//                 select = 2;
//             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
//                 if (select == 0) {
//                     if (pos == 50) {
//                         snake.changeColor(sf::Color::Green);
//                         path = "./lib/arcade_snake.so";
//                         pos = 300;
//                     } else if (pos == 100) {
//                         pacman.changeColor(sf::Color::Green);
//                         path = "./lib/arcade_pacman.so";
//                         pos = 300;
//                     }
//                     select = 1;
//                     sleep(0.5);
//                 } else if (select == 2) {
//                     if (pos == 300) {
//                         sfml.changeColor(sf::Color::Green);
//                         path += " ./lib/arcade_sfml.so";
//                     } else if (pos == 350) {
//                         ncurses.changeColor(sf::Color::Green);
//                         path += " ./lib/arcade_ncurses.so";
//                     } else if (pos == 400) {
//                         sdl.changeColor(sf::Color::Green);
//                         path += " ./lib/arcade_sdl.so";
//                     }
//                     select = 3;
//                 }
//             }
//             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && select == 2) {
//                 if (pos == 300) {
//                     pos = 350;
//                     ncurses.changeColor(sf::Color::Red);
//                     sfml.changeColor(sf::Color::White);
//                 } else if (pos == 350) {
//                     pos = 400;
//                     sdl.changeColor(sf::Color::Red);
//                     ncurses.changeColor(sf::Color::White);
//                 } else if (pos == 400) {
//                     pos = 300;
//                     sfml.changeColor(sf::Color::Red);
//                     sdl.changeColor(sf::Color::White);
//                 }
//             }
//             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && select == 2) {
//                 if (pos == 300) {
//                     pos = 400;
//                     sdl.changeColor(sf::Color::Red);
//                     sfml.changeColor(sf::Color::White);
//                 } else if (pos == 350) {
//                     pos = 300;
//                     sfml.changeColor(sf::Color::Red);
//                     ncurses.changeColor(sf::Color::White);
//                 } else if (pos == 400) {
//                     pos = 350;
//                     ncurses.changeColor(sf::Color::Red);
//                     sdl.changeColor(sf::Color::White);
//                 }
//             }
//             if (event.type == sf::Event::TextEntered) {
//                 if (event.text.unicode <= 126 && event.text.unicode >= 41) {
//                     enter = 1;
//                     name.text.setString(name.text.getString() + static_cast<char>(event.text.unicode));
//                 }
//                 if (event.text.unicode == 8) {
//                     std::string str = name.text.getString();
//                     str.pop_back();
//                     name.text.setString(str);
//                 }
//                 if (event.text.unicode == 13 && enter == 1 && select == 3 && name.text.getString() != "") {
//                     path += " " + name.text.getString();
//                     window.close();
//                 }
//             }
//         }
//         window.clear();
//         window.draw(game_title.text);
//         window.draw(snake.text);
//         window.draw(pacman.text);
//         window.draw(lib_title.text);
//         window.draw(sfml.text);
//         window.draw(ncurses.text);
//         window.draw(sdl.text);
//         window.draw(user.text);
//         window.draw(name.text);
//         window.display();
//     }
//     return path;
// }

// extern "C" IDisplay* create(void)
// {
//     return new Display();
// }
