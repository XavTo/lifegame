##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compil
##

SRCS =	gamelife.c \
		game_loop.c \
		update_map.c \
		pause.c \
		display_info.c \
		scrolldez.c \
		scrollzom.c \

OBJS = $(SRCS:.c=.o)

DEBUG = -g

CEXTRA = -W -Wall -Wextra

CINCLUDE = -I ./include

CGRAPHICS = -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

CFLAGS	= -L lib/ -lmy $(CINCLUDE) $(CEXTRA)

NAME = gamelife

all : $(NAME)

$(NAME) : $(OBJS)
		make -C lib/my
		gcc -o $(NAME) $(OBJS) $(CGRAPHICS) $(CFLAGS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

debug: $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJS) $(DEBUG) $(CGRAPHICS) $(CFLAGS)

x : re
	clear
	./$(NAME)