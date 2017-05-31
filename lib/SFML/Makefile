##
## Makefile for cpp_arcade in /Users/Vacca_J/Epitech/Tek2/cpp_arcade/lib/SFML
##
## Made by Vacca_J
## Login   <Vacca_J@epitech.net>
##
## Started on  Sun Apr 09 01:14:06 2017 Vacca_J
## Last update Sun Apr 09 01:14:06 2017 Vacca_J
##


CPP		=	g++

NAME		=	lib_arcade_sfml.so

RM		=	rm -f

MAKEFLAGS += --no-print-directory

LDFLAGS		+=	-shared -ldl -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

CPPFLAGS	+=	-std=c++11
CPPFLAGS	+=	-Werror -Wall -Wextra -fpic
CPPFLAGS	+=	-I./includes/ -I../../includes/ -I../../includes/utils -I../../includes/utils/data

SRCSDIR		=	sources
ROOTDIR		= ../../sources
UTILSDIR 	= $(ROOTDIR)/utils
DATASDIR 	= $(UTILSDIR)/data

SRCS		=	$(SRCSDIR)/SFML.cpp	\

SRCS		+=	$(UTILSDIR)/Position.cpp	\
			$(UTILSDIR)/Color.cpp		\
			$(UTILSDIR)/Texture.cpp	\

SRCS		+=	$(DATASDIR)/AData.cpp		\
			$(DATASDIR)/AVisual.cpp		\
			$(DATASDIR)/Audio.cpp		\
			$(DATASDIR)/Text.cpp		\
			$(DATASDIR)/AScene.cpp		\
			$(DATASDIR)/Camera.cpp		\
			$(DATASDIR)/Light.cpp		\
			$(DATASDIR)/Cube.cpp		\
			$(DATASDIR)/Sphere.cpp

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
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

fclean:		clean
		@$(RM) $(NAME) && \
		printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.' || \
		printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'


re:				fclean all
