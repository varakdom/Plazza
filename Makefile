##
## EPITECH PROJECT, 2022
## B-PDG-300-LIL-3-1-PDGRUSH3-cyprien.singez
## File description:
## Makefile
##

SRC	=	*.cpp

FLAGS	=	-g -Wall

NAME	=	plazza

all:
		g++ -o $(NAME) $(SRC) $(FLAGS) -lpthread -g

clean:
		rm -f *.o

fclean:	clean
		rm -f $(NAME)
		rm -f *.o

re: clean all