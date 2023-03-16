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
    void *handle = openlib("./lib/arcade_ncurses.so");
    if (!handle)
        return 1;
    creator create = (creator) dlsym(handle, "create");
    IDisplay *func = create();
    if (!func) {
        std::cerr << "Cannot load symbol 'printHello': " << dlerror() << '\n';
        dlclose(handle);
        return 1;
    }
    func->printHello();
    handle = openlib("./lib/arcade_sfml.so");
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    create = (creator) dlsym(handle, "create");
    func = create();
    if (!func) {
        std::cerr << "Cannot load symbol 'printHello': " << dlerror() << '\n';
        dlclose(handle);
        return 1;
    }
    func->printHello();
    func->createMenu();
    delete func;
    dlclose(handle);
    return 0;
}