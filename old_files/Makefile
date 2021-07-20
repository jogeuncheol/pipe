NAME = pipex

SRC = test.c

OBJ = $(SRC.c=.o)

LIBFT_DIR = ./libft/

LIBFT_LIB = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_LIB) .
	ar rc libft.a $(OBJ)
	gcc -lft -L. -o $(NAME) $(SRC)

clean :
	make clean -C $(LIBFT_DIR)

re : all
