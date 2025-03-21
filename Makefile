# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 15:01:28 by qsomarri          #+#    #+#              #
#    Updated: 2025/03/21 12:59:53 by qsomarri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT 

CC = @cc

CFLAGS = -Wall -Wextra -Werror -g -I./includes

RM = @rm -rf

MAKE = @make -C

SRCS_DIR = srcs

PARSER_DIR = parser

MAIN_DIR = main

SRCS =	$(SRCS_DIR)/$(MAIN_DIR)/minirt.c \
	$(SRCS_DIR)/$(PARSER_DIR)/file_parser.c \
	$(SRCS_DIR)/$(PARSER_DIR)/utils_parser.c \
	$(SRCS_DIR)/$(PARSER_DIR)/objects_parser.c \
	$(SRCS_DIR)/$(PARSER_DIR)/scene_parser.c \
	$(SRCS_DIR)/$(PARSER_DIR)/ft_atof.c \
	$(SRCS_DIR)/outputs.c \

OBJ_DIR = obj

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

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
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		@echo "\033[0;92m * $(NAME) program file was created\033[0m *"

# Construction de la libft
$(LIBFT):
	@$(MAKE) $(LIBFT_PATH) all

# Création du répertoire des objets
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets
clean:
	@$(MAKE) $(LIBFT_PATH) clean
	@$(RM) $(OBJ_DIR)
	@echo "\033[0;91m* $(NAME) object files was deleted *\033[0m"

# Nettoyage complet
fclean: clean
	@$(MAKE) $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

# Reconstruction complète
re: fclean all

.PHONY: all clean fclean re

