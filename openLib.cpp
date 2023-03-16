/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** test.cpp
*/

#include <iostream>
#include <dlfcn.h>
#include "IDisplay.hpp"

typedef IDisplay* (*creator) ();

void *openlib(std::string path)
{
    void *handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return NULL;
    }
    return handle;
}

int main(int ac, char **av)
{
    void *handle = openlib(av[1]);
    if (!handle)
        return 84;
    creator create = (creator) dlsym(handle, "create");
    IDisplay *menu = create();
    std::string buf = menu->createMenu();
    delete menu;
    dlclose(handle);
    return 0;
}