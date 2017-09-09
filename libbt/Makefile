# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mameyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 20:38:30 by mameyer           #+#    #+#              #
#    Updated: 2017/09/07 12:47:58 by mameyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libbt.a

SRC =		bt_clean_tree.c \
			bt_count_tree_nodes.c \
			bt_join_trees.c \
			bt_new_tree.c \
			bt_print_tree_prefix.c

OBJ =	$(patsubst %.c,%.o,$(SRC))

HEADER = ft.h

all : $(NAME)

$(NAME) :
	@ gcc -c $(SRC) -I $(HEADER) -Wall -Wextra -Werror
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@ echo "COMPILATION SUCCESS"

clean :
	@ rm -f $(OBJ)
	@ echo "ALL .o FILES HAVE BEEN DELETED"
	@ echo "CLEANING SUCCESS"

fclean : clean
	@ rm -f $(NAME)

re : fclean all

.PHONY : all re clean fclean
