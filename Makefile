# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayellin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 14:21:49 by ayellin           #+#    #+#              #
#    Updated: 2020/01/28 03:51:42 by ayellin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = 	stack.c
SOURCES_LIST_PS = push_swap.c
SOURCES_LIST_CH = checker.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
SOURCES_PS = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_PS))
SOURCES_CH = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_CH))


OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_LIST_PS = $(patsubst %.c, %.o, $(SOURCES_LIST_PS))
OBJECTS_LIST_CH = $(patsubst %.c, %.o, $(SOURCES_LIST_CH))

OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))
OBJECTS_PS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_PS))
OBJECTS_CH = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_CH))


# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(OBJECTS_PS) -o $(PUSH_SWAP)
	@echo "\n$(PUSH_SWAP): $(GREEN)$(PUSH_SWAP) object files were created$(RESET)"
	@echo "$(PUSH_SWAP): $(GREEN)$(PUSH_SWAP) was created$(RESET)"

$(CHECKER): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_CH)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(OBJECTS_CH) -o $(CHECKER)
	@echo "\n$(PUSH_SWAP): $(GREEN)$(CHECKER) object files were created$(RESET)"
	@echo "$(PUSH_SWAP): $(GREEN)$(CHECKER) was created$(RESET)"


$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(PUSH_SWAP): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(PUSH_SWAP): $(GREEN)creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "$(PUSH_SWAP): $(GREEN)Creating $(MINILIBX)...$(RESET)"
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(PUSH_SWAP): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(PUSH_SWAP): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(PUSH_SWAP): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(PUSH_SWAP)
	@echo "$(PUSH_SWAP): $(RED)$(PUSH_SWAP) was deleted$(RESET)"
	@rm -f $(CHECKER)
	@echo "$(PUSH_SWAP): $(RED)$(CHECKER) was deleted$(RESET)"
	@rm -f $(NAME_VS)
	@echo "$(PUSH_SWAP): $(RED)$(NAME_VS) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all