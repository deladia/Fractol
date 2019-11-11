# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deladia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/01 23:52:27 by deladia           #+#    #+#              #
#    Updated: 2019/11/11 17:22:20 by deladia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME = fractol 

CC = gcc

CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework Appkit -framework OpenCL

MY_LIB = ./libft/
MLX_LIB = ./mlx/
INC = ./mlx/ ./libft/includes/ ./includes
INCLUDES = -I ./mlx/ -I ./libft/includes/ -I ./includes/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))

SRC_DIR = ./src
OBJ_DIR = ./object

SRC_NAME = main.c set_default.c create_cl.c mouse_control.c helps.c errors.c put_str_on_win.c key_control.c
OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make build_lib
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_LIB) -lmlx -L $(MY_LIB) -lft $(INCLUDES) $(FRAMEWORKS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) 
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

build_lib:
	@make -sC $(MY_LIB)
	@make -sC $(MLX_LIB)

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C $(MLX_LIB)
	@make clean -C $(MY_LIB)

fclean:	clean
	@make clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(MY_LIB)
	
re:	fclean all
