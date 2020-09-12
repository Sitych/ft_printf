# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 13:19:23 by snorcros          #+#    #+#              #
#    Updated: 2020/02/05 16:34:31 by qjosmyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDES := ./includes/
CFLAGS := -Wall -Wextra -Werror
LIB_FLAG := -L libft/ -lft

#libft
SRC_LIBFT_LST = ft_atoi.c		ft_bzero.c		ft_memccpy.c	ft_memchr.c		ft_lstmerge.c\
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
		  free_table.c  ft_itoabase.c   ft_itoahex.c    ft_itoa_signed.c ft_strcut.c\
		  ft_stradd_front.c ft_stradd_back.c    ft_strreplace.c ft_strcat_front.c ft_itoadouble.c

LIBFT_DIR = libft/
HEADER_LIBFT = $(LIBFT_DIR)includes
LIBFT = $(LIBFT_DIR)libft.a
SRC_LIBFT = $(addprefix $(LIBFT_DIR), $(SRC_LIBFT_LST))
OBJ_LIBFT = $(patsubst %.c, %.o, $(SRC_LIBFT))

LIBFT_HEADERS_LIST = libft.h
LIBFT_HEADERS_DIR = $(LIBFT_DIR)includes/
LIBFT_HEADERS = $(addprefix $(LIBFT_HEADERS_DIR), $(LIBFT_HEADERS_LIST))

#ft_printf
SRC_PRINTF_LST =	fun_flags.c	fun_length.c length_bonus.c parse.c	placeholder.c	printf.c\
                    precision.c type_unixtime.c unixtime.c  type_color.c flag_hash.c\
                    funtypes_ubp.c funtypes_cdx_upx_o.c funtypes_sf_percent.c\
                    bonus_star.c get_flag_sign.c set_precision_width.c\
					ft_kek.c ft_double.c ft_longarith.c

PRINTF_DIR = srcs/
SRC_PRINTF = $(addprefix $(PRINTF_DIR), $(SRC_PRINTF_LST))
OBJ_DIR = objects/
OBJ_LST = $(patsubst %.c, %.o, $(SRC_PRINTF_LST))
OBJ_PRINTF	= $(addprefix $(OBJ_DIR), $(OBJ_LST))

HEADERS_LST = colors.h  funfortypes.h   libftprintf.h unixtime.h header_double.h
HEADERS = $(addprefix $(INCLUDES), $(HEADERS_LST))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ_LIBFT) $(OBJ_PRINTF)
	@ar rc $(NAME) $(OBJ_PRINTF) $(OBJ_LIBFT)
	ranlib $(NAME)
	make -C libft

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(PRINTF_DIR)%.c $(HEADERS)
	gcc $(CFLAGS) -c -I $(INCLUDES) -I $(LIBFT_HEADERS_DIR) $< -o $@

$(LIBFT):
	make -sC $(LIBFT_DIR)
	
clean:
	make -sC $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -sC $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
