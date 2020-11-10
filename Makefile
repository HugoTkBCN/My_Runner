##
## EPITECH PROJECT, 2018
## makefile
## File description:
## compile
##

SRC	=	my_runner.c	\
		src/event.c	\
		src/create/create_game_object.c	\
		src/create/destroy.c	\
		src/wallpaper.c	\
		src/create/create_runner.c	\
		src/create/create_wallpaper.c	\
		src/create/create_destroy_sound.c	\
		src/runner.c	\
		src/menu.c	\
		src/blocks.c	\
		src/collision.c	\
		src/score.c	\
		src/generate_blocks.c	\
		src/create/create_blocks.c	\
		src/create/create_menus.c	\
		utils/my_putchar.c	\
		utils/my_put_nbr.c	\
		utils/my_putstr.c	\
		utils/open_window.c	\
		utils/my_strlen.c	\
		utils/mem_alloc_2d_array.c	\
		utils/get_next_line.c	\
		utils/my_strdup.c	\
		utils/my_strcpy.c	\
		utils/convert.c	\
		utils/my_revstr.c

NAME	=	my_runner

OBJ	=	$(SRC:.c=.o)

LIB	=	-lcsfml-graphics -lcsfml-audio

FLAGS = -Wall -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) main.c $(OBJ) $(LIB) $(FLAGS)

clean:
	rm -rf $(OBJ)
fclean:		clean
	rm -rf $(NAME)

re:	fclean all
