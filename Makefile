# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 14:37:38 by ccavalca          #+#    #+#              #
#    Updated: 2025/09/15 00:23:38 by ccavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -I./Libft -I./ft_printf -I./minilibx

LIBFT_DIR = Libft
PRINTF_DIR = ft_printf
MLX_DIR = minilibx
SRCS_DIR = srcs

SRCS = $(SRCS_DIR)/main.c \
       $(SRCS_DIR)/map_reader.c \
       $(SRCS_DIR)/map_validator.c \
       $(SRCS_DIR)/path_validator.c \
       $(SRCS_DIR)/render.c \
       $(SRCS_DIR)/hooks.c \
       $(SRCS_DIR)/cleanup.c \
       $(SRCS_DIR)/game.c \

BONUS_SRCS = $(SRCS_DIR)/bonus_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/libftprintf.a
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(LIBFT_A) $(PRINTF_A) $(MLX_DIR)/libmlx.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) $(MLX_LIB) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(PRINTF_A):
	make -C $(PRINTF_DIR)

$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

bonus: $(NAME)_bonus

$(NAME)_bonus: $(PRINTF_A) $(MLX_DIR)/libmlx.a $(OBJS) $(BONUS_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) $(LIBFT) $(PRINTF) $(MLX_LIB) -o $(NAME)_bonus

re: fclean all

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME) $(NAME)_bonus
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

.PHONY: all clean fclean re bonus