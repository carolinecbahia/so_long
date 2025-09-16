# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 14:37:38 by ccavalca          #+#    #+#              #
#    Updated: 2025/09/16 01:33:59 by ccavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = $(NAME)_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -I./Libft -I./ft_printf -I./minilibx

LIBFT_DIR = Libft
PRINTF_DIR = ft_printf
MLX_DIR = minilibx
SRCS_DIR = srcs
BONUS_DIR = $(SRCS_DIR)/bonus

COMMON_SRCS = 	
				$(SRCS_DIR)/map_reader.c \
				$(SRCS_DIR)/hooks.c \

MANDATORY_SRCS = 	$(SRCS_DIR)/main.c \
					$(SRCS_DIR)/map_validator.c \
					$(SRCS_DIR)/path_validator.c \
					$(SRCS_DIR)/render.c \
					$(SRCS_DIR)/render_utils.c \
					$(SRCS_DIR)/game.c \
					$(SRCS_DIR)/cleanup.c \
					
BONUS_SRCS = 	$(wildcard $(BONUS_DIR)/*.c)

COMMON_OBJS = $(COMMON_SRCS:.c=.o)
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/libftprintf.a
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(LIBFT_A) $(PRINTF_A) $(MLX_DIR)/libmlx.a $(COMMON_OBJS) $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(MANDATORY_OBJS) $(LIBFT_A) $(PRINTF_A) $(MLX_LIB) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(PRINTF_A):
	make -C $(PRINTF_DIR)

$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

bonus: $(NAME_BONUS)

$(NAME)_bonus: $(PRINTF_A) $(MLX_DIR)/libmlx.a $(COMMON_OBJS) $(BONUS_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(BONUS_OBJS) $(LIBFT_A) $(PRINTF_A) $(MLX_LIB) -o $(NAME_BONUS)

re: fclean all

clean:
	rm -f $(COMMON_OBJS) $(MANDATORY_OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

.PHONY: all clean fclean re bonus