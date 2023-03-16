/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-corentin.fortes
** File description:
** test.cpp
*/

#include <iostream>
#include <dlfcn.h>

// void *openlib(char *path)
// {
//     void *handle = dlopen(path, RTLD_LAZY);
//     if (!handle) {
//         std::cerr << "Cannot open library: " << dlerror() << '\n';
//         return NULL;
//     }
//     return handle;
// }

int main(int ac, char **av)
{
    void *handle = dlopen("./libr.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    void (*func)() = (void (*)()) dlsym(handle, "printHello");
    if (!func) {
        std::cerr << "Cannot load symbol 'printHello': " << dlerror() << '\n';
        dlclose(handle);
        return 1;
    }
    func();
    handle = dlopen("./libr2.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    func = (void (*)()) dlsym(handle, "printHello");
    if (!func) {
        std::cerr << "Cannot load symbol 'printHello': " << dlerror() << '\n';
        dlclose(handle);
        return 1;
    }
    func();
    return 0;
}