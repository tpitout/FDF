# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhendric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 13:26:01 by nhendric          #+#    #+#              #
#    Updated: 2018/09/10 17:10:23 by tpitout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc -o
FLAG = -Wall -Werror -Wextra
MLXFLAG = -l mlx -framework OpenGL -framework AppKit
INC = -I ./includes
SRC = fdf.c map_read.c display.c tools.c
OBJ = $(SRC:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME):
	@make -C ./libft/
	@$(CC) $(NAME) $(SRC) $(FLAG) $(INC) ./libft/libft.a $(MLXFLAG)

clean:
	@make clean -C ./libft/

fclean: clean
	@make fclean -C ./libft/
	@$(RM) $(NAME)

re: fclean all
