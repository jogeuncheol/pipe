# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gejo <gejo@42seoul.kr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 02:30:17 by gejo              #+#    #+#              #
#    Updated: 2021/07/21 20:20:35 by gejo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs

SRC_B_DIR = srcs_b

BONUS_HIDE = .bonus

INCLUDE = include

SRC = $(SRC_DIR)/ft_main.c\
	  $(SRC_DIR)/ft_mlibft.c\
	  $(SRC_DIR)/ft_set_path.c\
	  $(SRC_DIR)/ft_set_cmd_arr.c\
	  $(SRC_DIR)/ft_set_cmd.c\
	  $(SRC_DIR)/ft_set_cmd_sp.c\
	  $(SRC_DIR)/ft_utils.c\
	  $(SRC_DIR)/ft_pipex.c\
	  $(SRC_DIR)/ft_open.c\
	  $(SRC_DIR)/ft_error.c

OBJ = $(SRC_DIR)/ft_main.o\
	  $(SRC_DIR)/ft_mlibft.o\
	  $(SRC_DIR)/ft_set_path.o\
	  $(SRC_DIR)/ft_set_cmd_arr.o\
	  $(SRC_DIR)/ft_set_cmd.o\
	  $(SRC_DIR)/ft_set_cmd_sp.o\
	  $(SRC_DIR)/ft_utils.o\
	  $(SRC_DIR)/ft_pipex.o\
	  $(SRC_DIR)/ft_open.o\
	  $(SRC_DIR)/ft_error.o

SRC_B = $(SRC_B_DIR)/ft_main_bonus.c\
		$(SRC_B_DIR)/ft_mlibft_bonus.c\
		$(SRC_B_DIR)/ft_set_path_bonus.c\
		$(SRC_B_DIR)/ft_set_cmd_arr_bonus.c\
		$(SRC_B_DIR)/ft_set_cmd_bonus.c\
		$(SRC_B_DIR)/ft_set_cmd_sp_bonus.c\
		$(SRC_B_DIR)/ft_utils_bonus.c\
		$(SRC_B_DIR)/ft_pipex_bonus.c\
		$(SRC_B_DIR)/ft_open_bonus.c\
		$(SRC_B_DIR)/ft_error_bonus.c

OBJ_B = $(SRC_B_DIR)/ft_main_bonus.o\
		$(SRC_B_DIR)/ft_mlibft_bonus.o\
		$(SRC_B_DIR)/ft_set_path_bonus.o\
		$(SRC_B_DIR)/ft_set_cmd_arr_bonus.o\
		$(SRC_B_DIR)/ft_set_cmd_bonus.o\
		$(SRC_B_DIR)/ft_set_cmd_sp_bonus.o\
		$(SRC_B_DIR)/ft_utils_bonus.o\
		$(SRC_B_DIR)/ft_pipex_bonus.o\
		$(SRC_B_DIR)/ft_open_bonus.o\
		$(SRC_B_DIR)/ft_error_bonus.o

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
