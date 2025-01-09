##
## EPITECH PROJECT, 2024
## MAKEFILE
## File description:
## makefile
##

SRC = src/my.c \
	  src/my2.c \
	  src/my3.c \
	  src/my_alloc.c \
	  src/parsing_file.c \
	  src/events.c \
	  src/display.c \
	  src/move_planes.c \
	  src/create.c \
	  src/int_to_str.c \
	  src/collisions.c \
	  src/quadtree.c \
	  src/free_all.c \
	  main.c

DEBUG = -ggdb -g3

CFLAGS = -Wall -Wextra -Werror

FLAG_CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

FLAG_MATH = -lm

OBJ = $(SRC:.c=.o)

all:	$(OBJ)
		gcc $(CFLAGS) $(OBJ) $(FLAG_CSFML) $(FLAG_MATH) -o my_radar

debug: $(OBJ)
		gcc $(CFLAGS) $(DEBUG) $(OBJ) $(FLAG_CSFML) $(FLAG_MATH) -o my_radar

clean:
	rm  -f $(OBJ)

fclean:
	make clean
	rm -f my_radar

re: fclean all
