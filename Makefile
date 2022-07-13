##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile project
##

SRC		=	src/my_sokoban.c	\
			src/map.c	\
			src/move.c	\
			src/height_move_keys.c	\
			src/side_move_keys.c	\
			src/replace_target.c	\
			src/print.c	\
			src/target_reset.c	\
			src/loose_condition.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

debug:
	gcc -o $(NAME) $(SRC) -lncurses -g

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
