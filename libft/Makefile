# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akay <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 05:45:29 by akay              #+#    #+#              #
#    Updated: 2018/08/13 12:26:48 by tpitout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc -c
CFLAGS = -Wall -Wextra -Werror
INC = -I ./includes/
SRCS = ./srcs/*.c
OBJ = *.o
RM = rm -rf

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[97mCompiling libft...\033[0m"
	@sleep 1
	@echo "\033[32mCompiled.\033[0m"

clean:
	@$(RM) $(OBJ)
	@echo "\033[97mRemoving object files...\033[0m"
	@sleep 1
	@echo "\033[31mRemoved.\033[0m"

fclean:
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@echo "\033[97mRemoving object files...\033[0m"
	@sleep 1
	@echo "\033[31mRemoved.\033[0m\n"
	@echo "\033[97mRemoving libft.a...\033[0m"
	@sleep 1
	@echo "\033[31mRemoved.\033[0m\n"

re: fclean all
