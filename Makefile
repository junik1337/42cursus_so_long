# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 18:43:01 by ayassir           #+#    #+#              #
#    Updated: 2022/03/18 13:15:43 by ayassir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_BONUS	=	so_long_bonus

SRC_M		=	srcs/exit.c srcs/map_init_tools.c srcs/so_long_utils.c srcs/game_init.c \
				srcs/map_init_tools_2.c srcs/map_init_tools_3.c srcs/fill_map.c srcs/images_hook.c \
				srcs/exit_1.c srcs/so_long_utils_2.c so_long.c\
				utils/get_next_line.c utils/get_next_line_utils.c \

SRC_B		=	srcs_b/exit_bonus.c srcs_b/map_init_tools_bonus.c srcs_b/so_long_utils_bonus.c srcs_b/game_init_bonus.c \
				srcs_b/map_init_tools_bonus_1.c srcs_b/map_init_tools_bonus_2.c srcs_b/fill_map_bonus.c srcs_b/images_hook_bonus.c \
				srcs_b/exit_bonus_1.c srcs_b/so_long_utils_bonus_1.c srcs_b/mlx_animation.c \
				utils/get_next_line.c utils/get_next_line_utils.c so_long_bonus.c srcs_b/enemy_mouvement.c\

PRINTF		=	ft_printf/libftprintf.a
PRINTF_DIR	=	ft_printf/

LIBFT		=	libft/libft.a
LIBFT_DIR	=	libft/

FLAGS		=	-Wall -Wextra -Werror
MLX			=	-lmlx -framework OpenGL -framework AppKit

HEADER		=	includes/so_long.h
HEADER_B	=	includes/so_long_bonus.h

RM			=	rm -rf

red			=	`tput setaf 1`
green		=	`tput setaf 2`
white		=	`tput setaf 7`

OBJ_M = $(SRC_M:.c=.o) 
OBJ_B = $(SRC_B:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ_M) $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $(MLX) $^ -o $(NAME)

$(NAME_BONUS): $(OBJ_B) $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $(MLX) $^ -o $(NAME_BONUS)

%.o : SRC_M/%.c $(HEADER)
	@$(CC) $(FLAGS) $(MLX) -c $<

%.o : SRC_B/%.c $(HEADER_B)
	@$(CC) $(FLAGS) $(MLX) -c $<
	
$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)
	
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ_M) $(OBJ_B)
	@ $(RM) $(NAME)
	@ $(RM) $(NAME_BONUS)
	
fclean:
	@$(RM) $(OBJ_M) $(OBJ_B)
	@ $(MAKE) fclean -C $(PRINTF_DIR)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(NAME)
	@ $(RM) $(NAME_BONUS)
	
re: fclean all

mandatory:	$(NAME)
bonus:		$(NAME_BONUS)

m:			mandatory
b:			bonus

.PHONY: all clean fclean re mandatory m bonus b