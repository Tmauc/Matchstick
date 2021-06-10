##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/prog.c			\
		src/error.c			\
		src/setup.c			\
		src/get_map.c			\
		src/free.c			\
		src/check_buffer_line.c		\
		src/check_buffer_matches.c	\
		src/remove_matches_player.c	\
		src/print_map.c			\
		src/ai_fcnts.c			\
		src/compt_line.c		\
		src/check_for_algo_one_line.c	\
		src/remove_max_line.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	=	-g3 -Wall -W -Wextra

CPPFLAGS=	-I include

LDFLAGS	=	-L lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	make clean -C lib/my

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/my

re: fclean all
