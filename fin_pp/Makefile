NAME =	pipex

CFLAGS = -g3 -fsanitize=address -Wall -Wextra -Werror

SRC	=	pipex.c\
		mlibft.C\
		setpath_fn.c\
		ft_pipex.c\
		set_cmd_fn.c\
		set_cmd_sp_fn.c\
		utils_fn.c\
		valid_check_fn.c\
		cmd_arr_fn.c\
		ft_open.c\
		error_fn.c

OBJ =	pipex.o\
		mlibft.o\
		setpath_fn.o\
		ft_pipex.o\
		set_cmd_fn.o\
		set_cmd_sp_fn.o\
		utils_fn.o\
		valid_check_fn.o\
		cmd_arr_fn.o\
		ft_open.o\
		error_fn.o

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all