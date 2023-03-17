##
## EPITECH PROJECT, 2022
## B-OOP-400-MAR-4-1-arcade-corentin.fortes
## File description:
## Makefile
##

NAME = 	arcade
SRC =	*.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME) :
	g++ -shared -fPIC ./NCURSES/ncurse.cpp -o ./lib/arcade_ncurses.so
	g++ -shared -fPIC ./SFML/sfml.cpp -o ./lib/arcade_sfml.so
	g++ -shared -fPIC ./SDL2/sdl2.cpp -o ./lib/arcade_sdl2.so
	g++ openLib.cpp -ldl -o arcade -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -lncurses -lSDL2

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :	 fclean all
