##
## EPITECH PROJECT, 2022
## B-OOP-400-MAR-4-1-arcade-corentin.fortes
## File description:
## Makefile
##

NAME = 	arcade
SRC =	*.cpp
OBJ = $(SRC:.cpp=.o)


all : games graphicals core
	

core :
	g++ openLib.cpp core.cpp -ldl -o arcade -fno-gnu-unique -std=c++17

games :
	g++ -shared -fPIC ./menu/menu.cpp -o ./lib/arcade_menu.so -std=c++17
	g++ -shared -fPIC ./snake/snake.cpp -o ./lib/arcade_snake.so -std=c++17

graphicals :
	g++ -shared -fPIC ./NCURSES/ncurse.cpp -o ./lib/arcade_ncurses.so -std=c++17 -lncurses
	g++ -shared -fPIC ./SFML/sfml.cpp -o ./lib/arcade_sfml.so -std=c++17 -lsfml-window -lsfml-system -lsfml-graphics
	g++ -shared -fPIC ./SDL2/sdl2.cpp -o ./lib/arcade_sdl2.so -std=c++17 -lSDL2 -lSDL2_image -lSDL2_ttf

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f ./lib/*.so

re :	 fclean all
