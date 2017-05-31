##
## Makefile for  in /home/fagnol_r/Tek_2/CPP/cpp_arcade/games/Starfox
##
## Made by Romain Fagnola
## Login   <fagnol_r@epitech.net>
##
## Started on  Mon Apr  3 17:54:54 2017 Romain Fagnola
## Last update Mon Apr  3 18:01:39 2017 Romain Fagnola
##

CPP             =       g++

NAME            =       lib_arcade_solarfox.so

RM              =       rm -f

MAKEFLAGS += --no-print-directory

LDFLAGS         +=      -shared -ldl

CPPFLAGS        +=      -std=c++11
CPPFLAGS        +=      -Werror -Wall -Wextra -fpic
CPPFLAGS        +=      -I./includes/ -I../../includes/ -I../../includes/utils -I../../includes/utils/data

SRCSDIR         =       sources
ROOTDIR         = ../../sources
UTILSDIR        = $(ROOTDIR)/utils
DATASDIR        = $(UTILSDIR)/data

SRCS            =       $(SRCSDIR)/Solarfox.cpp    \
			$(SRCSDIR)/Ennemy.cpp			\
			$(SRCSDIR)/Missile.cpp	\

SRCS            +=      $(UTILSDIR)/Position.cpp        \
                        $(UTILSDIR)/Color.cpp           \
                        $(UTILSDIR)/Texture.cpp \
                        $(UTILSDIR)/LoadController.cpp  \
			$(UTILSDIR)/Model3D.cpp		\

SRCS            +=      $(DATASDIR)/AData.cpp           \
                        $(DATASDIR)/AVisual.cpp         \
                        $(DATASDIR)/Audio.cpp           \
                        $(DATASDIR)/Text.cpp            \
                        $(DATASDIR)/AScene.cpp          \
                        $(DATASDIR)/Camera.cpp          \
                        $(DATASDIR)/Light.cpp           \
                        $(DATASDIR)/Cube.cpp            \
                        $(DATASDIR)/Sphere.cpp

OBJS            =       $(SRCS:.cpp=.o)


all:            $(NAME)

$(NAME):        $(OBJS)
		@$(CPP) $(OBJS) $(LDFLAGS) -o $(NAME) && \
		printf "[\033[1;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.' || \
		printf "[\033[1;31mfailed\033[0m] % 31s\n" $(NAME) | tr ' ' '.'
		@mv $(NAME) ../$(NAME)

.cpp.o:
		@$(CPP) $(CPPFLAGS) $(LDFLAG) -c $< -o $@ && \
		printf "[\033[1;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.' || \
		printf "[\033[1;31mfailed\033[0m] % 31s\n" $< | tr ' ' '.'

clean:
		@$(RM) $(OBJS) && \
		printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.' || \
		printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'

fclean:         clean
		@$(RM) $(NAME) && \
		printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.' || \
		printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'


re:                             fclean all
