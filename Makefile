# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 13:34:57 by bramalho@st       #+#    #+#              #
#    Updated: 2026/01/16 01:38:51 by bramalho@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# ============================================================================ #
#                                  NAMES                                       #
# ============================================================================ #

NAME = so_long

# ============================================================================ #
#                                 COMPILER                                     #
# ============================================================================ #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=42

# ============================================================================ #
#                                DIRECTORIES                                   #
# ============================================================================ #

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
GNL_DIR = GNL

LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MLX_DIR = minilibx-linux

# ============================================================================ #
#                                  FILES                                       #
# ============================================================================ #

GNL_SRCS =	$(GNL_DIR)/get_next_line.c \
			$(GNL_DIR)/get_next_line_utils.c

SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/map_reader.c \
		$(SRC_DIR)/map_validation.c \
		$(SRC_DIR)/map_path_validation.c\
		$(SRC_DIR)/map_initialization.c \
		$(SRC_DIR)/map_render.c \
		$(SRC_DIR)/render_utils.c \
		$(SRC_DIR)/input_handler.c \
		$(SRC_DIR)/enemy_handler.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/cleanup.c

GNL_OBJS = $(GNL_SRCS:$(GNL_DIR)/%.c=$(OBJ_DIR)/%.o)
SRC_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS = $(GNL_OBJS) $(SRC_OBJS)

# ============================================================================ #
#                                 LIBRARIES                                    #
# ============================================================================ #

LIBFT =		$(LIBFT_DIR)/libft.a
PRINTF =	$(PRINTF_DIR)/libftprintf.a
MLX =		$(MLX_DIR)/libmlx.a

# ============================================================================ #
#                                  FLAGS                                       #
# ============================================================================ #

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR) -I$(GNL_DIR)
LIBS_DIR = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -L$(MLX_DIR)
LIBS = -lftprintf -lft -lmlx -lXext -lX11 -lm

# ============================================================================ #
#                                  RULES                                       #
# ============================================================================ #

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_DIR) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)✓$(RESET) Compiled $<"

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)✓$(RESET) Compiled $<"

$(LIBFT):
	@echo "$(GREEN)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
	@echo "$(GREEN)Compiling ft_printf...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR) --no-print-directory

$(MLX):
	@echo "$(GREEN)Compiling MiniLibX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory
	@echo "$(GREEN)🧹 Object files cleaned!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory
	@echo "$(GREEN)🗑️  Everything cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
