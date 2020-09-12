# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snorcros <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:42:32 by snorcros          #+#    #+#              #
#    Updated: 2019/10/12 12:54:47 by snorcros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c		ft_bzero.c		ft_memccpy.c	ft_memchr.c		ft_lstmerge.c\
	  ft_memcmp.c	ft_memcpy.c		ft_memmove.c 	ft_memset.c		ft_lstremove_if.c\
	  ft_strlen.c	ft_strcmp.c		ft_isalnum.c	ft_lstqsort.c	ft_lstadd_back.c\
	  ft_strcpy.c	ft_strncpy.c	ft_strcat.c		ft_strncat.c	ft_lstfind.c\
	  ft_strlcat.c	ft_strchr.c		ft_strrchr.c	ft_strstr.c		ft_lstmap.c\
	  ft_strnstr.c	ft_strncmp.c	ft_isalpha.c	ft_isdigit.c	ft_putnbr_fd.c\
	  ft_isascii.c	ft_toupper.c	ft_tolower.c	ft_isprint.c	ft_strdup.c\
	  ft_memalloc.c	ft_memdel.c		ft_strnew.c		ft_strdel.c		ft_lstswap.c\
	  ft_strclr.c	ft_striter.c	ft_striteri.c	ft_strmap.c		ft_strmapi.c \
	  ft_strequ.c	ft_strnequ.c	ft_strsub.c		ft_strjoin.c	ft_strtrim.c\
	  ft_putchar.c	ft_putendl.c	ft_putstr.c		ft_strsplit.c	ft_itoa.c\
	  ft_putnbr.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c get_next_line.c\
	  ft_lstnew.c	ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c		ft_lstiter.c \
	  ft_qsort.c	ft_lstsize.c	ft_lstlast.c	ft_lsti.c		ft_lstreverse.c\
	  free_table.c  ft_itoabase.c   ft_itoahex.c    ft_itoa_signed.c ft_itoadouble.c\
	  ft_stradd_front.c ft_stradd_back.c    ft_strreplace.c ft_strcat_front.c ft_strcut.c

SRC0 = ft_atoi.o	ft_bzero.o		ft_memccpy.o	ft_memchr.o		ft_lstmerge.o\
	  ft_memcmp.o	ft_memcpy.o		ft_memmove.o 	ft_memset.o		ft_lstremove_if.o\
	  ft_strlen.o	ft_strcmp.o		ft_isalnum.o	ft_lstqsort.o	ft_lstadd_back.o\
	  ft_strcpy.o	ft_strncpy.o	ft_strcat.o		ft_strncat.o	ft_lstfind.o\
	  ft_strlcat.o	ft_strchr.o		ft_strrchr.o	ft_strstr.o		ft_lstmap.o\
	  ft_strnstr.o	ft_strncmp.o	ft_isalpha.o	ft_isdigit.o	ft_putnbr_fd.o\
	  ft_isascii.o	ft_toupper.o	ft_tolower.o	ft_isprint.o	ft_strdup.o\
	  ft_memalloc.o	ft_memdel.o		ft_strnew.o		ft_strdel.o		ft_lstswap.o\
	  ft_strclr.o	ft_striter.o	ft_striteri.o	ft_strmap.o		ft_strmapi.o\
	  ft_strequ.o	ft_strnequ.o	ft_strsub.o		ft_strjoin.o	ft_strtrim.o\
	  ft_putchar.o	ft_putendl.o	ft_putstr.o		ft_strsplit.o	ft_itoa.o\
	  ft_putnbr.o	ft_putchar_fd.o	ft_putstr_fd.o	ft_putendl_fd.o get_next_line.o\
	  ft_lstnew.o	ft_lstdelone.o	ft_lstdel.o		ft_lstadd.o		ft_lstiter.o\
	  ft_qsort.o	ft_lstsize.o	ft_lstlast.o	ft_lsti.o		ft_lstreverse.o\
	  free_table.o  ft_itoabase.o   ft_itoahex.o    ft_itoa_signed.o ft_strcut.o\
	  ft_stradd_front.o ft_stradd_back.o ft_strreplace.o ft_strcat_front.o ft_itoadouble.o

HEADER = includes

all: $(NAME)

$(NAME): $(SRC0)
	@ar rc $@ $^

%.o: %.c $(HEADER)
	@gcc -Wall -Wextra -Werror -c $< -I $(HEADER)
clean:
	@rm -f $(SRC0)

fclean: clean
	@rm -f $(NAME) 

re: fclean all
