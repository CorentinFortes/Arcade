##
## EPITECH PROJECT, 2022
## B-OOP-400-MAR-4-1-arcade-corentin.fortes
## File description:
## Makefile
##

NAME = 	arcade
SRC =	*.cpp
OBJ = $(SRC:.cpp=.o)


all :
	g++ -shared -fPIC ./menu/menu.cpp -o ./lib/arcade_menu.so
	g++ -shared -fPIC ./NCURSES/ncurse.cpp -o ./lib/arcade_ncurses.so
	g++ -shared -fPIC ./SFML/sfml.cpp -o ./lib/arcade_sfml.so
	g++ -shared -fPIC ./SDL2/sdl2.cpp -o ./lib/arcade_sdl2.so
	g++ *.cpp -ldl -o arcade -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -lncurses -lSDL2 -lSDL2_image -lSDL2_ttf

core :
	g++ openLib.cpp -ldl -o arcade -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -lncurses -lSDL2 -lSDL2_image -lSDL2_ttf

games :
	g++ -shared -fPIC ./menu/menu.cpp -o ./lib/arcade_menu.so

graphicals :
	g++ -shared -fPIC ./NCURSES/ncurse.cpp -o ./lib/arcade_ncurses.so
	g++ -shared -fPIC ./SFML/sfml.cpp -o ./lib/arcade_sfml.so
	g++ -shared -fPIC ./SDL2/sdl2.cpp -o ./lib/arcade_sdl2.so

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f ./lib/*.so

re :	 fclean all
