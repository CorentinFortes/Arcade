/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** ITest.hpp
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class IDisplay
{
    public:
    virtual ~IDisplay() = default;
    virtual void printHello(void) =0;
    virtual void createMenu() =0;
};
