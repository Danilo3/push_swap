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

LIBFT_SRC =  ./ft_arr/ft_int_arr_cmp.c \
             ./ft_convert/ft_atoi.c \
             ./ft_convert/ft_atol.c \
             ./ft_convert/ft_itoa.c \
             ./ft_convert/ft_itoa_base.c \
             ./ft_convert/ft_itostr.c \
             ./ft_convert/ft_lltoa.c \
             ./ft_convert/ft_lltoa_base.c \
             ./ft_convert/ft_uitoa_base.c \
             ./ft_convert/ft_ulltoa_base.c \
             ./ft_digit/ft_count_digits.c \
             ./ft_is/ft_isalnum.c \
             ./ft_is/ft_isalpha.c \
             ./ft_is/ft_isascii.c \
             ./ft_is/ft_isdigit.c \
             ./ft_is/ft_islower.c \
             ./ft_is/ft_isprint.c \
             ./ft_is/ft_isspace.c \
             ./ft_is/ft_isupper.c \
             ./ft_lst/ft_lstadd.c \
             ./ft_lst/ft_lstdel.c \
             ./ft_lst/ft_lstdelone.c \
             ./ft_lst/ft_lstiter.c \
             ./ft_lst/ft_lstlen.c \
             ./ft_lst/ft_lstmap.c \
             ./ft_lst/ft_lstnew.c \
             ./ft_math/ft_ispsqrt.c \
             ./ft_math/ft_max.c \
             ./ft_math/ft_min.c \
             ./ft_math/ft_power.c \
             ./ft_math/ft_sqrt.c \
             ./ft_mem/ft_bzero.c \
             ./ft_mem/ft_memalloc.c \
             ./ft_mem/ft_memccpy.c \
             ./ft_mem/ft_memchr.c \
             ./ft_mem/ft_memcmp.c \
             ./ft_mem/ft_memcpy.c \
             ./ft_mem/ft_memdel.c \
             ./ft_mem/ft_memmove.c \
             ./ft_mem/ft_memrcpy.c \
             ./ft_mem/ft_memset.c \
             ./ft_printf/srcs/ft_ldtoa.c \
             ./ft_printf/srcs/ft_printf.c \
             ./ft_printf/srcs/ft_putwchar.c \
             ./ft_put/ft_putchar.c \
             ./ft_put/ft_putchar_fd.c \
             ./ft_put/ft_putchar_utf8_fd.c \
             ./ft_put/ft_putendl.c \
             ./ft_put/ft_putendl_fd.c \
             ./ft_put/ft_putnbr.c \
             ./ft_put/ft_putnbr_fd.c \
             ./ft_put/ft_putstr.c \
             ./ft_put/ft_putstr_fd.c \
             ./ft_std/ft_exit.c \
             ./ft_str/ft_str_find.c \
             ./ft_str/ft_str_func_not_find.c \
             ./ft_str/ft_str_shift_left.c \
             ./ft_str/ft_str_startswith.c \
             ./ft_str/ft_strcat.c \
             ./ft_str/ft_strchr.c \
             ./ft_str/ft_strchri.c \
             ./ft_str/ft_strclr.c \
             ./ft_str/ft_strcmp.c \
             ./ft_str/ft_strcpy.c \
             ./ft_str/ft_strcspn.c \
             ./ft_str/ft_strdel.c \
             ./ft_str/ft_strdup.c \
             ./ft_str/ft_strequ.c \
             ./ft_str/ft_striter.c \
             ./ft_str/ft_striteri.c \
             ./ft_str/ft_strjoin.c \
             ./ft_str/ft_strjoinf.c \
             ./ft_str/ft_strlcat.c \
             ./ft_str/ft_strlen.c \
             ./ft_str/ft_strmap.c \
             ./ft_str/ft_strmapi.c \
             ./ft_str/ft_strncat.c \
             ./ft_str/ft_strncmp.c \
             ./ft_str/ft_strncpy.c \
             ./ft_str/ft_strnequ.c \
             ./ft_str/ft_strnew.c \
             ./ft_str/ft_strnlen.c \
             ./ft_str/ft_strnstr.c \
             ./ft_str/ft_strrchr.c \
             ./ft_str/ft_strrev.c \
             ./ft_str/ft_strsplit.c \
             ./ft_str/ft_strstr.c \
             ./ft_str/ft_strsub.c \
             ./ft_str/ft_strsubf.c \
             ./ft_str/ft_strtrim.c \
             ./ft_str/ft_tolower.c \
             ./ft_str/ft_toupper.c \
             ./ft_parse/ft_parse_int_str \

PRINTF_SRC_DIR = ./ft_printf/srcs/

PRINTF_INC_DIR = ./ft_printf/includes/

SRCS = $(addprefix $(PRINTF_SRC_DIR), $(PRINTF_SRC)) $(LIBFT_SRC)

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
