# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mameyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 20:38:30 by mameyer           #+#    #+#              #
#    Updated: 2017/09/04 03:53:04 by mameyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =		ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_atoi.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_is_blank.c \
			ft_is_space.c \
			ft_cnt_words.c \
			ft_print_alphabet.c \
			ft_print_numbers.c \
			ft_del_fb.c \
			get_next_line.c \
			ft_debug.c \
			ft_print_tab.c

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
