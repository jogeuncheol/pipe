# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gejo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/03 18:51:13 by gejo              #+#    #+#              #
#    Updated: 2021/07/03 19:12:27 by gejo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	pipex

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs

SRC_B_DIR = srcs_b

BONUS_HIDE = .bonus

INCLUDE = include

SRC	=	$(SRC_DIR)/pipex.c\
		$(SRC_DIR)/putstr_lib.c\
		$(SRC_DIR)/string_lib.c\
		$(SRC_DIR)/setpath_fn.c\
		$(SRC_DIR)/ft_pipex.c\
		$(SRC_DIR)/set_cmd_fn.c\
		$(SRC_DIR)/set_cmd_sp_fn.c\
		$(SRC_DIR)/utils_fn.c\
		$(SRC_DIR)/valid_check_fn.c\
		$(SRC_DIR)/cmd_arr_fn.c\
		$(SRC_DIR)/ft_open.c\
		$(SRC_DIR)/error_fn.c

OBJ =	$(SRC_DIR)/pipex.o\
		$(SRC_DIR)/putstr_lib.o\
		$(SRC_DIR)/string_lib.o\
		$(SRC_DIR)/setpath_fn.o\
		$(SRC_DIR)/ft_pipex.o\
		$(SRC_DIR)/set_cmd_fn.o\
		$(SRC_DIR)/set_cmd_sp_fn.o\
		$(SRC_DIR)/utils_fn.o\
		$(SRC_DIR)/valid_check_fn.o\
		$(SRC_DIR)/cmd_arr_fn.o\
		$(SRC_DIR)/ft_open.o\
		$(SRC_DIR)/error_fn.o

SRC_B = $(SRC_B_DIR)/pipex_bonus.c\
		$(SRC_B_DIR)/putstr_lib_bonus.c\
		$(SRC_B_DIR)/string_lib_bonus.c\
		$(SRC_B_DIR)/setpath_fn_bonus.c\
		$(SRC_B_DIR)/ft_pipex_bonus.c\
		$(SRC_B_DIR)/set_cmd_fn_bonus.c\
		$(SRC_B_DIR)/set_cmd_sp_fn_bonus.c\
		$(SRC_B_DIR)/utils_fn_bonus.c\
		$(SRC_B_DIR)/valid_check_fn_bonus.c\
		$(SRC_B_DIR)/cmd_arr_fn_bonus.c\
		$(SRC_B_DIR)/ft_open_bonus.c\
		$(SRC_B_DIR)/error_fn_bonus.c

OBJ_B =	$(SRC_B_DIR)/pipex_bonus.o\
		$(SRC_B_DIR)/putstr_lib_bonus.o\
		$(SRC_B_DIR)/string_lib_bonus.o\
		$(SRC_B_DIR)/setpath_fn_bonus.o\
		$(SRC_B_DIR)/ft_pipex_bonus.o\
		$(SRC_B_DIR)/set_cmd_fn_bonus.o\
		$(SRC_B_DIR)/set_cmd_sp_fn_bonus.o\
		$(SRC_B_DIR)/utils_fn_bonus.o\
		$(SRC_B_DIR)/valid_check_fn_bonus.o\
		$(SRC_B_DIR)/cmd_arr_fn_bonus.o\
		$(SRC_B_DIR)/ft_open_bonus.o\
		$(SRC_B_DIR)/error_fn_bonus.o

all : $(NAME)

$(NAME) : $(OBJ)
	rm -f $(OBJ_B) $(BONUS_HIDE)
	gcc $(CFLAGS) -L./$(INCLUDE) -o $(NAME) $(OBJ)

bonus : $(BONUS_HIDE)

$(BONUS_HIDE) : $(OBJ_B)
	touch $(BONUS_HIDE)
	rm -f $(OBJ)
	gcc $(CFLAGS) -L./$(INCLUDE) -o $(NAME) $(OBJ_B)

clean :
	rm -f $(OBJ) $(OBJ_B) $(BONUS_HIDE)

fclean : clean
	rm -f $(NAME)

re : fclean all
