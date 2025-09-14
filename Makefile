# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 14:37:38 by ccavalca          #+#    #+#              #
#    Updated: 2025/09/14 03:44:29 by ccavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -ILibft -Ift_printf -Iminilibx

LIBFT_DIR = Libft/
PRINTF_DIR = ft_printf/
MLX_DIR = minilibx/
SRCS_DIR = srcs/
INCLUDES_DIR = includes/

SRCS = $(SRCS_DIR)/main.c \
       $(SRCS_DIR)/map_reader.c \
       $(SRCS_DIR)/map_validator.c \
       $(SRCS_DIR)/path_validator.c \
       $(SRCS_DIR)/render.c \
       $(SRCS_DIR)/hooks.c \
       $(SRCS_DIR)/utils.c

BONUS_SRCS = $(SRCS_DIR)/bonus_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext

$(NAME): $(LIBFT) $(PRINTF) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_LIB) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

bonus: $(LIBFT) $(PRINTF) $(MLX_LIB) $(OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) $(LIBFT) $(PRINTF) $(MLX_LIB) -o $(NAME)_bonus

re: fclean all

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME) $(NAME)_bonus
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

.PHONY: all clean fclean re bonus $(LIBFT) $(PRINTF) $(MLX_LIB)