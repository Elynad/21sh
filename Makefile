# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mameyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 12:11:53 by mameyer           #+#    #+#              #
#    Updated: 2017/09/04 04:46:47 by mameyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC =	main.c \
		init.c \
		free.c \
		parsing.c \
		history.c \
		cursor.c \
		termcaps.c \
		splitter.c \
		lexer.c \
		str_split.c \
		str_split_whitespaces.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT = libft/libft.a libdll/libdll.a libbt/libbt.a

CC = clang

FLAGS = -Wall -g -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) -lncurses $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

%.o :		$(SRC_PATH)/%.c
			$(CC) -o $@ -c $< $(FLAGS)

$(LIBFT):
			make -C ./libft/
			make -C ./libdll/
			make -C ./libbt/

clean:
			rm -rf $(OBJ)
			make clean -C ./libft/
			make clean -C ./libdll/
			make clean -C ./libbt/

fclean:		clean
			rm -rf $(NAME)
			make fclean -C ./libft/
			make fclean -C ./libdll/
			make fclean -C ./libbt/

re:			fclean all

.PHONY : all re clean fclean
