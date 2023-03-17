#include <iostream>
#include <ncurses.h>
#include "../IDisplay.hpp"

class Display : public IDisplay
{
    public:
    Display(){};
    ~Display(){};
    virtual void printHello(void);
    virtual std::string createMenu();
};
