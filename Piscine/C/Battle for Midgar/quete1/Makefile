NAME		=		ragnarok

CC		=		gcc

SRC		=		main.c			\
				readline.c		\
				attack.c		\
				attack2.c		\
				main2.c			\
				monster_attack.c

OBJ		=		$(SRC:%.c=%.o)

CFLAGS		=		-W -Wall -Werror -ansi -pedantic

LDFLAGS		=		-L. ./libmy.a

RM		=		rm -f

$(NAME):	$(OBJ)
		$(MAKE) -C ./lib/
		cp ./lib/libmy.a .
		$(CC) -o $(NAME) $(LDFLAGS) $(OBJ)


all:		$(NAME)


clean:
		$(RM) $(OBJ)
		$(RM) *~

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
