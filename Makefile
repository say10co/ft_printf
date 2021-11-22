NAME = libftprintf.a

ft =  $(wildcard ./utils/ft_*.c) ./utils/conv_ptr.c ./libft/ft_calloc.c ./libft/ft_strjoin.c ./libft/ft_strlen.c 

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

