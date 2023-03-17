#include <iostream>
#include <curses.h>
#include <vector>
#include <string>
#include "../IDisplay.hpp"

class Display : public IDisplay
{
    private:
    void printMenu(std::vector <std::string> menu, std::vector <std::string> games);
    std::string printUser();

    public:
    Display(){};
    ~Display(){};
    std::string createMenu();
};
