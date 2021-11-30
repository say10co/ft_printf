# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adriouic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 01:53:39 by adriouic          #+#    #+#              #
#    Updated: 2021/11/30 04:01:48 by adriouic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = utils_b/conv_ptr.c utils_b/ft_atoi.c utils_b/ft_atoi_minus.c utils_b/ft_dot.c utils_b/ft_execption.c utils_b/ft_getLen.c utils_b/ft_get_percision.c utils_b/ft_isdigit.c utils_b/ft_isspecifier.c utils_b/ft_itoa.c  utils_b/ft_prcent.c utils_b/ft_print_base.c utils_b/ft_put_percent.c utils_b/ft_put_space_zero.c utils_b/ft_put_unsigned_nbr.c utils_b/ft_putchar.c utils_b/ft_putnbr.c utils_b/ft_putnbr_b.c utils_b/ft_putstr.c utils_b/ft_putstr_b.c utils_b/ft_set_args.c utils_b/ft_set_struct.c utils_b/ft_strdup.c utils_b/ft_strjoin.c utils_b/ft_strlen.c utils_b/ft_substr.c ft_printf.c
 

OBJS = ${FILES:.c=.o}


INCLUDES = ./includes

all : $(NAME)


$(NAME): $(OBJS)

%.o : %.c
	cc -Wall -Werror -Wextra -c $< -o $@ -I $(INCLUDES)
	ar rc $(NAME) ${<:.c=.o}

bonus : fclean all

clean :
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: re clean all fclean
