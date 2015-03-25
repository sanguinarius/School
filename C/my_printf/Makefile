##
## Makefile for Makefile for libmy in /Users/laxa/Documents/Piscine/C/Jour_08/egloff_j/Makefile
## 
## Made by EGLOFF Julien
## Login   <egloff_j@etna-alternance.net>
## 
## Started on  Thu Apr  3 09:04:32 2014 EGLOFF Julien
## Last update Wed Nov 12 15:56:43 2014 Julien EGLOFF
##

CC	= gcc

NAME	= libmy_printf_`uname -m`-`uname -s`

SRC	= my_printf.c		\
	  operators2.c		\
	  operators.c

OBJ	= $(SRC:%.c=%.o)

RM	= rm -f

CFLAGS	= -W -Wall -Werror -ansi -pedantic

LDFLAGS = -I. -L. ./lib/libmy.a


all:		makelib my_printf_dynamic my_printf_static

my_printf_dynamic:	$(OBJ) makelib
			ar r $(NAME).a $(OBJ)
			ranlib $(NAME).a

my_printf_static:	$(OBJ) makelib
			$(CC) -c $(CFLAGS) -fpic $(SRC)
			$(CC) -shared -o $(NAME).so $(LDFLAGS) $(OBJ)

makelib:
		$(MAKE) -C ./lib/
		cp ./lib/libmy.a .

clean:
		$(RM) $(OBJ)
		$(MAKE) -C ./lib/ clean

fclean:		clean
		$(RM) $(NAME).so
		$(RM) $(NAME).a
		$(MAKE) -C ./lib/ fclean

re:		fclean all
