##
## Makefile for my_printf in /home/wilgen_t//afs/projets/my_printf
## 
## Made by thomas wilgenbus
## Login   <wilgen_t@epitech.net>
## 
## Started on  Mon Nov 15 13:44:30 2010 thomas wilgenbus
## Last update Sat Jun  4 16:57:05 2011 adrien despujol
##

NAME=		libmy_printf_`uname -m`-`uname -s`.a

SRC=		my_printf.c \
		str_utils.c \
		my_putnbr_base.c \
		aff.c \
		#display_error.c

CFLAGS=		-W -Wall -ansi -pedantic

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

re:		fclean clean $(NAME)

$(NAME):	$(OBJ)
	ar crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(NAME)