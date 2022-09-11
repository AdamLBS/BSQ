##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME = bsq
SRC =	my_bsq.c \
		my_get_nbr.c \
		my_putstr.c \
		my_putchar.c \
		utils.c \
		utils2.c \
		utils3.c \

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ)

all : 	$(NAME)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY : all clean fclean re
