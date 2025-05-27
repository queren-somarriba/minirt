# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiech <jpiech@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 15:01:28 by qsomarri          #+#    #+#              #
#    Updated: 2025/05/27 14:16:02 by jpiech           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT 

CC = @cc

CFLAGS = -Wall -Wextra -Werror -g3 -I./includes

RM = @rm -rf

MAKE = @make -s -C

SRCS_DIR = srcs

PARSER_DIR = parser

MAIN_DIR = main

FREE_DIR = free

DISPLAY_DIR = display

UI_DIR = ui

INTERSECTIONS_DIR = intersections

SRCS =	$(SRCS_DIR)/$(MAIN_DIR)/minirt.c \
	$(SRCS_DIR)/$(MAIN_DIR)/list_utils.c \
	$(SRCS_DIR)/$(MAIN_DIR)/vector_utils.c \
	$(SRCS_DIR)/$(MAIN_DIR)/vector_utils2.c \
	$(SRCS_DIR)/$(MAIN_DIR)/outputs.c \
	$(SRCS_DIR)/$(PARSER_DIR)/file_parser.c \
	$(SRCS_DIR)/$(PARSER_DIR)/elements_parser.c \
	$(SRCS_DIR)/$(PARSER_DIR)/utils_parser.c \
	$(SRCS_DIR)/$(PARSER_DIR)/objects_parser.c \
	$(SRCS_DIR)/$(PARSER_DIR)/scene_parser.c \
	$(SRCS_DIR)/$(PARSER_DIR)/ft_atof.c \
	$(SRCS_DIR)/$(FREE_DIR)/free_objects.c \
	$(SRCS_DIR)/$(FREE_DIR)/free_scene.c \
	$(SRCS_DIR)/$(UI_DIR)/event.c \
	$(SRCS_DIR)/$(UI_DIR)/resize_and_translate.c \
	$(SRCS_DIR)/$(UI_DIR)/rotations.c \
	$(SRCS_DIR)/$(DISPLAY_DIR)/display.c \
	$(SRCS_DIR)/$(DISPLAY_DIR)/ray.c \
	$(SRCS_DIR)/$(DISPLAY_DIR)/color.c \
	$(SRCS_DIR)/$(DISPLAY_DIR)/color_utils.c \
	$(SRCS_DIR)/$(INTERSECTIONS_DIR)/intersections.c \
	$(SRCS_DIR)/$(INTERSECTIONS_DIR)/sphere.c \
	$(SRCS_DIR)/$(INTERSECTIONS_DIR)/plane.c \
	$(SRCS_DIR)/$(INTERSECTIONS_DIR)/cylinder.c \
	$(SRCS_DIR)/$(INTERSECTIONS_DIR)/cylinder_caps.c \

OBJ_DIR = obj

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./mlx_linux

MLX = $(MLX_PATH)/libmlx.a

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(OBJ_DI)/%.o: $(BONUS_SRCS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -03 -c $< -o $@

# Cible principale
all: $(NAME)

# Création de l'exécutable
$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		@echo "\033[0;92m * $(NAME) program file was created\033[0m *"

# Construction de la libft
$(LIBFT):
	@$(MAKE) $(LIBFT_PATH) all
	
# Construction de la minilibx
$(MLX) :
	@$(MAKE) $(MLX_PATH) all

# Création du répertoire des objets
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets
clean:
	@$(MAKE) $(LIBFT_PATH) fclean
	@$(MAKE) $(MLX_PATH) clean
	@$(RM) $(OBJ_DIR)
	@echo "\033[0;91m* $(NAME) object files was deleted *\033[0m"

# Nettoyage complet
fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

# Reconstruction complète
re: fclean all

test :
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) scenes/1.rt

.PHONY: all clean fclean re

