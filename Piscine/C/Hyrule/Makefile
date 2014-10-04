CC	=	gcc

NAME	=	hyrule

SRC	=	main.c

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-W -Wall -Werror -ansi -pedantic

LDFLAGS	=	-L. ./libmy.a

RM	=	rm -f

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(LDFLAGS) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
