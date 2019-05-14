# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 00:03:57 by pvandamm          #+#    #+#              #
#    Updated: 2018/12/29 17:18:29 by pvandamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIB = ./libft/libft.a

LIB_PATH = ./libft

INCLUDES = -I libft/includes -I ./includes

SRC_PATH = ./srcs

OBJ_PATH = ./objs

SRC_NAME = 	checker.c 								\
			lst_func.c								\
			create_list.c							\
			push.c									\
			reverse_rotate.c						\
			rotate.c								\
			visualizer.c							\
			swap.c									\
			utils.c									\

SRC_NAME2 = push_swap.c								\
			resolve.c								\
			short_resolve.c							\
			lst_func.c								\
			create_list.c							\
			push.c									\
			visualizer.c							\
			find_median.c							\
			reverse_rotate.c						\
			rotate.c								\
			swap.c									\
			utils.c									\

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_NAME2 = $(SRC_NAME2:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

SRC2 = $(addprefix $(SRC_PATH)/, $(SRC_NAME2))

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

OBJ2 = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME2))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIB) -o $(NAME)
	@echo "\x1b[36m[CHECKER COMPILED]\x1b[0m"

$(NAME2): $(OBJ2)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(OBJ2) $(INCLUDES) $(LIB) -o $(NAME2)
	@echo "\x1b[36m[PUSH_SWAP COMPILED]\x1b[0m"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	@make clean -C $(LIB_PATH)
	@rm -rf $(OBJ)
	@rm -rf $(OBJ2)
	@echo "\033[33mall $(NAME) and $(NAME2) .o files are removed\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME) $(NAME2)
	@echo "\033[31m$(NAME) and $(NAME2) is deleted\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
