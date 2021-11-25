NAME = libftprintf.a

ft_b =  $(wildcard ./utils_b/ft_*.c) ./utils_b/conv_ptr.c ft_printf_bonus.c
 
ft =  $(wildcard ../utils/ft_*.c) ../utils/conv_ptr.c ../ft_printf.c

oft = ${ft:.c=.o}
oft_b = ${ft_b:.c=.o}

INCLUDES = ./includes

all : bonus

%.o : %.c
	gcc -Wall -Werror -Wextra -c $< -o $@ -I $(INCLUDES)
	ar rc $(NAME) ${<:.c=.o}

$(NAME): $(oft)

bonus : fclean $(oft_b)

clean :
	rm -f $(oft) $(oft_b)
fclean: clean
	rm -f $(NAME)
re : all

