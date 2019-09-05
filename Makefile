# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deladia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/01 23:52:27 by deladia           #+#    #+#              #
#    Updated: 2019/09/03 20:30:30 by deladia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME = fractol 

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = /usr/local/lib/ 

MY_LIB = ./libft/

INCLUDES = -I /usr/local/include -I ./libft/include

SRC = main.c set_default.c create_cl.c mouse_control.c helps.c errors.c put_str_on_win.c key_control.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MY_LIB)
	$(CC) $(CFLAGS) -L $(LIB) -lmlx -L $(MY_LIB) -lft $(INCLUDES) -framework OpenGL -framework AppKit -framework OpenCL -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(CFLAGS) $(INCLUDES)
		
clean:
	@make clean -C $(MY_LIB)
	@/bin/rm -f $(OBJ)

fclean:	clean
	@make clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(MY_LIB)
	
re:	fclean all
