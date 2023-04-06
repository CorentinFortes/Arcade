##
## EPITECH PROJECT, 2022
## B-OOP-400-MAR-4-1-arcade-corentin.fortes
## File description:
## Makefile
##

NAME = 	arcade
SRC =	*.cpp
OBJ = $(SRC:.cpp=.o)
HOMEBREW = /opt/homebrew/Cellar/
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SDL2_FLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image

INCLUDE_PATH = -std=c++20 -I./include -I./menu -I./snake -I./NCURSES -I./SFML -I./SDL2 -I./lib 

ifeq ($(shell uname -s),Linux)
	# Linux
	INCLUDE_PATH += -fno-gnu-unique
endif
ifeq ($(shell uname -s),Darwin)
	# Mac OS X
	SFML_FLAGS += -I$(HOMEBREW)sfml/2.5.1_2/include -L$(HOMEBREW)sfml/2.5.1_2/lib
	SDL2_FLAGS += -I$(HOMEBREW)sdl2/2.26.4/include/SDL2
	SDL2_FLAGS += -I$(HOMEBREW)sdl2/2.26.4/include -L$(HOMEBREW)sdl2/2.26.4/lib
	SDL2_FLAGS += -I$(HOMEBREW)sdl2_image/2.6.3/include -L$(HOMEBREW)sdl2_image/2.6.3/lib
	SDL2_FLAGS += -I$(HOMEBREW)sdl2_ttf/2.20.2/include -L$(HOMEBREW)sdl2_ttf/2.20.2/lib -lSDL2_ttf
endif


all : games graphicals core
	

core :
	g++ openLib.cpp all.cpp core.cpp -o $(NAME) -ldl $(INCLUDE_PATH) -g3

games :
	g++ -shared -fPIC ./menu/menu.cpp all.cpp -o ./lib/arcade_menu.so -std=c++17 -g 
	g++ -shared -fPIC ./snake/snake.cpp all.cpp -o ./lib/arcade_snake.so -std=c++17 -g
	g++ -shared -fPIC ./pacman/pacman.cpp all.cpp -o ./lib/arcade_pacman.so -std=c++17 -g

graphicals :
	g++ -shared -fPIC ./NCURSES/ncurse.cpp all.cpp -o ./lib/arcade_ncurses.so -lncurses $(INCLUDE_PATH)
	g++ -shared -fPIC ./SFML/sfml.cpp all.cpp -o ./lib/arcade_sfml.so $(SFML_FLAGS) $(INCLUDE_PATH)
	g++ -shared -fPIC ./SDL2/sdl2.cpp all.cpp -o ./lib/arcade_sdl2.so $(SDL2_FLAGS) $(INCLUDE_PATH)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f ./lib/*.so

re :	 fclean all
