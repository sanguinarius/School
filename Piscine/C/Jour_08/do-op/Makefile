##
## Makefile for Makefile in /Users/laxa/Documents/Piscine/C/Jour_08/egloff_j/do-op
## 
## Made by EGLOFF Julien
## Login   <laxa>
## 
## Started on  Thu Apr  3 16:06:27 2014 EGLOFF Julien
## Last update Thu Apr  3 16:06:28 2014 EGLOFF Julien
##

CC	= gcc

NAME	= do-op

SRC	= main.c	\
	  do_op.c	\
	  math.c

OBJ	= $(SRC:%.c=%.o)

CFLAGS	= -W -Wall -Werror -ansi -pedantic

LDFLAGS	=  -L. -lmy -I.

RM	= rm -f


$(NAME):	$(OBJ)
		$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
