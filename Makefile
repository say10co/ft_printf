NAME = libftprintf.a

ft =  $(wildcard ./utils/ft_*.c) ./utils/conv_ptr.c ft_printf.c

oft = ${ft:.c=.o}

INCLUDES = ./includes

all : $(NAME)

%.o : %.c
	gcc -Wall -Werror -Wextra -c $< -o $@ -I $(INCLUDES)
	ar rc $(NAME) ${<:.c=.o}

$(NAME): $(oft)

clean :
	rm -f $(oft)
fclean: clean
	rm -f $(NAME)
re : all

