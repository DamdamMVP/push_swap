# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 13:14:31 by dalebran          #+#    #+#              #
#    Updated: 2024/10/29 03:33:40 by dalebran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR = inc
OBJ_DIR = obj
SRC_DIR = src

SRC_FILES = main stack_utils stack_init push reverse_rotate rotate swap is_functions utils move cost_calc is_functions2
SRC = $(addsuffix .c, $(SRC_FILES))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRCS:.c=.o))

all: $(LIBFT) $(NAME)
	@echo "push_swap created"

$(NAME): $(OBJ)
	@echo "Creation of executable $(NAME)..."
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compilation of $<..."
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR) -c $< -o $@

$(LIBFT):
	@echo "Compilation of Libft library..."
	@$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@echo "Cleaning of objects..."
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Cleaning of library files..."
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

test: re
	@echo "Compilation & test of push_swap with valgrind..."
	@valgrind ./push_swap $(filter-out $@,$(MAKECMDGOALS))

norminette:
	@echo "Norminette de $(NAME) et $(LIBFT_DIR)..."
	@if norminette $(SRC_DIR)/ $(INC_DIR)/ src_bonus/ $(LIBFT_DIR)/$(SRC_DIR)/ $(LIBFT_DIR)/$(INC_DIR)/ | grep -v "OK!" | grep -q "Error!"; then \
		norminette $(SRC_DIR)/ $(INC_DIR)/ src_bonus/ $(LIBFT_DIR)/$(SRC_DIR)/ $(LIBFT_DIR)/$(INC_DIR)/ | grep -v "OK!" | \
		while read line; do \
			if echo $$line | grep -q "Error!"; then \
				echo "\033[0;31m$$line\033[0m"; \
			else \
				echo "$$line"; \
			fi; \
		done; \
	else \
		echo "\033[0;32mAll files are norminette friendly !\033[0m"; \
	fi

# BONUS_PART
NAME_BONUS = checker
SRC_DIR_BONUS = src_bonus
OBJ_DIR_BONUS = obj_bonus
SRC_FILES_BONUS = main stack_utils stack_init push reverse_rotate rotate swap is_functions utils move cost_calc is_functions2
SRC_BONUS = $(addsuffix .c, $(SRC_FILES_BONUS))
SRCS_BONUS = $(addprefix $(SRC_DIR_BONUS)/, $(SRC_BONUS))
OBJ_BONUS = $(patsubst $(SRC_DIR_BONUS)/%, $(OBJ_DIR_BONUS)/%, $(SRCS_BONUS:.c=.o))

bonus: $(LIBFT) $(NAME_BONUS)
	@echo "checker created"

test_bonus: re bonus
	@echo "Compilation & test of checker with valgrind..."
	@valgrind ./checker $(filter-out $@,$(MAKECMDGOALS))

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "Creation of executable $(NAME_BONUS)..."
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)
	
$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@echo "Compilation of $<..."
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR) -c $< -o $@

.PHONY: all clean fclean re test bonus
