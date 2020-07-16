# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 22:22:35 by ccolemon          #+#    #+#              #
#    Updated: 2019/09/13 22:55:49 by ccolemon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP = push_swap
CHECKER = checker

FLAGS = -Wall -Wextra -Werror

DARK_RED = \033[2;31m
DARK_GRAY = \033[01;30m
DARK_GREEN = \033[2;32m
DARK_PURPLE = \033[2;35m
RED = \033[0;31m
GREEN = \033[0;32m
WHITE = \033[0m
PURPLE = \033[0;35m
CHM = ✅

LIB_DIR	= libft
LIBLINK	= -L libft/ -lft
LIB = libft/libft.a

SRC_DIR = libps

MAIN_PS_FILE = pushswap.c
MAIN_CH_FILE = checker.c

MAIN_INC = libps/pushswap.h

SRC_FILES =	check_sort.c \
			ft_qsort.c \
			sort.c \
			exc_sort.c \
			to_neib.c \
			create.c \
			end.c \
			get.c \
			pop.c \
			print_stack.c \
			push.c \
			reverse_rotate.c \
			rotate.c \
			set_neib.c \
			set_ops.c \
			set_pos.c \
			swap.c \
			valid_command.c \
			valid_num.c

OBJ_DIR = objects

SRC_PS = $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(SRC_DIR)/,$(MAIN_PS_FILE))
SRC_CH = $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(SRC_DIR)/,$(MAIN_CH_FILE))

OBJ_PS = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o)) $(addprefix $(OBJ_DIR)/,$(MAIN_PS_FILE:.c=.o))
OBJ_CH = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o)) $(addprefix $(OBJ_DIR)/,$(MAIN_CH_FILE:.c=.o))

.PHONY: clean all re fclean directory git test del

all: directory $(LIB) $(PUSHSWAP) $(CHECKER)

$(PUSHSWAP): $(OBJ_PS)
	@gcc $(FLAGS) -o $@  $(OBJ_PS) $(LIB)

$(CHECKER): $(OBJ_CH)
	@gcc $(FLAGS) -o $@  $(OBJ_CH) $(LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(MAIN_INC)
	@gcc $(FLAGS) -c $< -o $@

$(LIB):
	@make -C $(LIB_DIR)

directory: $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	
fclean: clean
	@rm -rf $(PUSHSWAP)
	@rm -rf $(CHECKER)
	@make -C $(LIB_DIR) fclean

re: fclean all

git: clean
	@git add .
	@git status
	@git commit -m "all correct"
	@git push
	@echo "$(PURPLE)git $(CHM)$(WHITE)"

test:
	@reset
	@echo "$(DARK_GREEN)Start compilation, please wait...\n$(WHITE)"
	@make && clear
	@sh test/test.sh

del: fclean
	@xattr -rc .
	@rm -rf test/command_pushswap test/test_norminette test/test_valgrind
	@find . \( -iname "a.out" -iname "a.out.*" -o -iname "*.gch" -o -iname ".DS_STORE" -o -iname ".vscode" -o -iname "*.dSYM" \) -exec rm -rf {} \;
	@find . \( -iname ".git" \) -mindepth 2 -exec rm -rf {} \;
	@reset
