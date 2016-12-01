# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alao <alao@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 15:45:38 by alao              #+#    #+#              #
#    Updated: 2016/12/01 18:48:26 by alao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

N_INC = wolf.h

N_SRCS =	wolf.c				\
			parser.c			\
			init.c				\
			hooker.c			\
			items.c				\
			immersion.c			\
			engine.c			\
			rendering.c			\
			sprite.c			\
			sprite_helper.c		\
			onscreen.c			\
			leveling.c			\
			mlx_helper.c

X_LFT = -L$(P_LFT) -lft
X_MLX = -L$(P_MLX) -lmlx -framework OpenGL -framework AppKit

P_SRCS = srcs/
P_OBJ = obj/
I_INC = includes
I_LFT = libft/includes
P_LFT = libft
P_MLX = minilibx

NOC=\033[0m
OKC=\033[32;05m
ERC=\033[31m
WAC=\033[33m

CC = gcc
CC_FLAGS = -g -Wall -Wextra -Werror

INC = $(addprefix -I,$(I_INC) $(I_LFT) $(P_MLX))
SRC = $(addprefix $(P_SRCS),$(N_SRCS))
OBJ = $(addprefix $(P_OBJ),$(OBJ_NAME))

OBJ_NAME = $(N_SRCS:.c=.o)

all: $(NAME)

project: clean proj

proj: $(OBJ)
	@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ) $(X_LFT) $(X_MLX)
	@echo "$(OKC)$(NAME): compilation success!$(NOC)"

$(NAME): $(OBJ)
	@make -C $(P_LFT)
	@make -C $(P_MLX)
	@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ) $(X_LFT) $(X_MLX)
	@echo "$(OKC)$(NAME): ready$(NOC)"

$(P_OBJ)%.o: $(P_SRCS)%.c
	@echo "$(OKC)\c"
	@mkdir -p $(P_OBJ)
	@$(CC) $(CC_FLAGS) -o $@ -c $^ $(INC)
	@echo -n █
	@echo "$(NOC)\c"

clean:
	@make -C $(P_LFT) clean
	@rm -rf $(P_OBJ)
	@echo "$(WAC)$(NAME): removing ./obj/$(NOC)"

fclean: clean
	@make -C $(P_LFT) fclean
	@make -C $(P_MLX) clean
	@rm -f $(NAME)
	@echo "$(WAC)$(NAME): removing executable$(NOC)"

re: fclean all
