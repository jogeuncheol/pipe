NAME =	pipex

CFLAGS = -Wall -Wextra -Werror

SRC	=	pipex.c\
		mlibft.C\
		setpath_fn.c\
		error_fn.c

OBJ =	pipex.o\
		mlibft.o\
		setpath_fn.o\
		error_fn.o

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean all