# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gejo <gejo@42seoul.kr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 02:30:17 by gejo              #+#    #+#              #
#    Updated: 2021/07/21 02:30:19 by gejo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall

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

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(CFLAGS) -L./$(INCLUDE) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
