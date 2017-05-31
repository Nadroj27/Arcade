##
## Makefile for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade
##
## Made by Vacca_J
## Login   <Vacca_J@epitech.net>
##
## Started on  Sun Apr 09 01:15:24 2017 Vacca_J
## Last update Sun Apr 09 01:15:24 2017 Vacca_J
##

CPP		=	g++

NAME		=	arcade

RM		=	rm -f

MAKEFLAGS += --no-print-directory

LDFLAGS		+=	-ldl

CPPFLAGS	+=	-std=c++11
CPPFLAGS	+=	-Werror -Wall -Wextra -fpic
CPPFLAGS	+=	-I./includes/ -I./includes/utils -I./includes/utils/data

SRCSDIR		=	sources
UTILSDIR	=	$(SRCSDIR)/utils
DATASDIR	=	$(UTILSDIR)/data

SRCS		=	$(SRCSDIR)/main.cpp	\
					$(SRCSDIR)/Arcade.cpp	\
					$(SRCSDIR)/MenuController.cpp \
					$(SRCSDIR)/ScoreManager.cpp \

SRCS		+=	$(UTILSDIR)/Position.cpp	\
			$(UTILSDIR)/Color.cpp		\
			$(UTILSDIR)/Texture.cpp	\
			$(UTILSDIR)/LoadController.cpp	\
			$(UTILSDIR)/Model3D.cpp	\

SRCS		+=	$(DATASDIR)/AData.cpp		\
			$(DATASDIR)/AVisual.cpp		\
			$(DATASDIR)/Audio.cpp		\
			$(DATASDIR)/Text.cpp		\
			$(DATASDIR)/AScene.cpp		\
			$(DATASDIR)/Camera.cpp		\
			$(DATASDIR)/Light.cpp		\
			$(DATASDIR)/Cube.cpp		\
			$(DATASDIR)/Sphere.cpp	\

OBJS		=	$(SRCS:.cpp=.o)

GAMEDIR		=	./games
SNAKEDIR	=	$(GAMEDIR)/Snake
SOLARDIR	=	$(GAMEDIR)/SolarFox

GRAPHDIR	=	./lib
NCURSESDIR	=	$(GRAPHDIR)/NCurses
SFMLDIR		=	$(GRAPHDIR)/SFML

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CPP) $(OBJS) $(LDFLAGS) -o $(NAME) && \
		printf "[\033[1;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.' || \
		printf "[\033[1;31mfailed\033[0m] % 31s\n" $(NAME) | tr ' ' '.'
		@make -C $(SNAKEDIR)
		@make -C $(SOLARDIR)

GRAPH:
		@make -C $(NCURSESDIR)
		@make -C $(SFMLDIR)

GRAPH_CLEAN:
		@make -C $(NCURSESDIR) clean
		@make -C $(SFMLDIR) clean

GRAPH_RE:
		@make -C $(NCURSESDIR) fclean
		@make -C $(SFMLDIR)	fclean
		@make -C $(SFMLDIR) all
		@make -C $(NCURSESDIR) all


.cpp.o:
		@$(CPP) $(CPPFLAGS) $(LDFLAG) -c $< -o $@ && \
		printf "[\033[1;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.' || \
		printf "[\033[1;31mfailed\033[0m] % 31s\n" $< | tr ' ' '.'

clean:
		@$(RM) $(OBJS) && \
		printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.' || \
		printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'
		@make -C $(SNAKEDIR) clean
		@make -C $(SOLARDIR) clean

		@make -C $(NCURSESDIR) clean
		@make -C $(SFMLDIR) clean

fclean:		clean
		@$(RM) $(NAME) && \
		printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.' || \
		printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'
		@make -C $(SNAKEDIR) fclean
		@make -C $(SOLARDIR) fclean

re:
		@make -C . fclean
		@make -C $(SNAKEDIR) fclean
		@make -C $(SOLARDIR) fclean

		@make -C . all
		@make -C $(SNAKEDIR) all
		@make -C $(SOLARDIR) all
