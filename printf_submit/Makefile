NAME = libftprintf.a

files = utils/conv_ptr.c utils/ft_calloc.c utils/ft_getLen.c utils/ft_isspecifier.c utils/ft_memset.c \
	 utils/ft_prcent.c utils/ft_print_base.c utils/ft_put_insigned_nbr.c utils/ft_put_percent.c \
	 utils/ft_putchar.c utils/ft_putnbr.c utils/ft_putstr.c utils/ft_strjoin.c utils/ft_strlen.c ft_printf.c

objs = ${files:.c=.o}

INCLUDES = ./includes

all : $(NAME)

%.o : %.c
	gcc -Wall -Werror -Wextra -c $< -o $@ -I $(INCLUDES)
	ar rc $(NAME) ${<:.c=.o}

$(NAME): $(objs)

clean :
	rm -f $(objs)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: fclean re all clean
