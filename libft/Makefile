# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayellin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 14:21:49 by ayellin           #+#    #+#              #
#    Updated: 2020/02/26 10:50:07 by dan              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

PRINTF_SRC = exp_util.c            \
            color_util.c          \
            flags_parser.c        \
            float_util.c          \
            ft_ldtoa.c            \
            ft_printf.c           \
            ft_putwchar.c         \
            get_digit.c           \
            get_float.c           \
            get_float_part.c      \
            get_int_part.c        \
            long_arithmetic.c     \
            precision_parser.c    \
            print_basic.c         \
            print_char.c          \
            print_d_buf.c         \
            print_digit_buf.c     \
            print_e_buf.c         \
            print_f_buf.c         \
            print_float.c         \
            print_hex.c           \
            print_oct.c           \
            print_other.c         \
            print_sd_buf.c        \
            print_str.c           \
            print_ud.c            \
            print_util.c          \
            print_ws.c            \
            printf_constants.c    \
            round_float.c         \
            size_parser.c         \
            spec_format_parser.c  \
            spec_util.c           \
            special_float_values.c \
            specificator.c        \
            type_func_table.c     \
            type_parser.c         \
            util.c                \
            width_parser.c        \

LIBFT_SRC = ft_atoi.c  \
            ft_bzero.c  \
            ft_count_digits.c \
            ft_exit.c        \
            ft_init_arr.c       \
            ft_int_arr_cmp.c    \
            ft_isalnum.c        \
            ft_isalpha.c        \
            ft_isascii.c        \
            ft_isdigit.c        \
            ft_islower.c        \
            ft_isprint.c        \
            ft_isspace.c        \
            ft_isupper.c        \
            ft_itoa.c           \
            ft_itostr.c         \
            ft_lstadd.c         \
            ft_lstdel.c         \
            ft_lstdelone.c      \
            ft_lstiter.c        \
            ft_lstlen.c         \
            ft_lstmap.c         \
            ft_lstnew.c         \
            ft_memalloc.c       \
            ft_memccpy.c        \
            ft_memchr.c         \
            ft_memcmp.c         \
            ft_memcpy.c         \
            ft_memdel.c         \
            ft_memmove.c        \
            ft_memrcpy.c        \
            ft_memset.c         \
            ft_power.c          \
            ft_putchar.c        \
            ft_putchar_fd.c     \
            ft_putchar_utf8_fd.c \
            ft_putendl.c            \
            ft_putendl_fd.c     \
            ft_putnbr.c         \
            ft_putnbr_fd.c      \
            ft_putstr.c         \
            ft_putstr_fd.c      \
            ft_str_find.c       \
            ft_str_func_not_find.c \
            ft_str_shift_left.c    \
            ft_str_startswith.c     \
            ft_strcat.c             \
            ft_strchr.c         \
            ft_strchri.c        \
            ft_strclr.c         \
            ft_strcmp.c         \
            ft_strcpy.c         \
            ft_strcspn.c        \
            ft_strdel.c         \
            ft_strdup.c         \
            ft_strequ.c         \
            ft_striter.c        \
            ft_striteri.c       \
            ft_strjoin.c        \
            ft_strjoinf.c       \
            ft_strlcat.c        \
            ft_strlen.c         \
            ft_strmap.c         \
            ft_strmapi.c        \
            ft_strncat.c        \
            ft_strncmp.c        \
            ft_strncpy.c        \
            ft_strnequ.c        \
            ft_strnew.c         \
            ft_strnlen.c        \
            ft_strnstr.c        \
            ft_strrchr.c        \
            ft_strrev.c         \
            ft_strsplit.c       \
            ft_strstr.c         \
            ft_strsub.c         \
            ft_strsubf.c        \
            ft_strtrim.c        \
            ft_tolower.c        \
            ft_toupper.c        \

LIBFT_ADD_SRC = ./ft_math/ft_ispsqrt.c \
                ./ft_math/ft_max.c \
                ./ft_math/ft_min.c \
                ./ft_math/ft_sqrt.c \
                ./ft_convert/ft_itoa_base.c \
                ./ft_convert/ft_lltoa.c    \
                ./ft_convert/ft_lltoa_base.c \
                ./ft_convert/ft_uitoa_base.c \
                ./ft_convert/ft_ulltoa_base.c \
                ./ft_convert.ft_atol.c  \
                ./ft_gnl/get_next_line.c

PRINTF_SRC_DIR = ./ft_printf/srcs/

PRINTF_INC_DIR = ./ft_printf/includes/

SRCS = $(addprefix $(PRINTF_SRC_DIR), $(PRINTF_SRC)) $(LIBFT_SRC) $(LIBFT_ADD_SRC)

OBJ = $(SRCS:.c=.o)

LIBFT_INC = ./includes/

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c
	    $(CC) $(CFLAGS) -I$(LIBFT_INC) -I$(PRINTF_INC_DIR) -c -o $@ $<
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
