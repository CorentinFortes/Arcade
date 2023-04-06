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
	  rm -fr ./lib/*.dSYM
	  rm -fr *.dSYM
	

core :
	g++ openLib.cpp all.cpp core.cpp -ldl -o arcade -fno-gnu-unique -std=c++17 -g

games :
	g++ -shared -fPIC ./menu/menu.cpp all.cpp -o ./lib/arcade_menu.so $(INCLUDE_PATH) -g3
	g++ -shared -fPIC ./snake/snake.cpp all.cpp -o ./lib/arcade_snake.so $(INCLUDE_PATH) -g3
	g++ -shared -fPIC ./pacman/pacman.cpp all.cpp -o ./lib/arcade_pacman.so $(INCLUDE_PATH) -g3

graphicals :
	g++ -shared -fPIC ./NCURSES/ncurse.cpp all.cpp -o ./lib/arcade_ncurses.so -std=c++17 -lncurses -g
	g++ -shared -fPIC ./SFML/sfml.cpp all.cpp -o ./lib/arcade_sfml.so -std=c++17 -lsfml-window -lsfml-system -lsfml-graphics -g
	g++ -shared -fPIC ./SDL2/sdl2.cpp all.cpp -o ./lib/arcade_sdl2.so -std=c++17 -lSDL2 -lSDL2_image -lSDL2_ttf -g

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f ./lib/*.so


re :	 fclean all