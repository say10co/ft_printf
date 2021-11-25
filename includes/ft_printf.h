#ifndef FT_PRINTF_H
# define FT_PRINTF_H
	
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

int		ft_printf(const char *placeHolders, ...);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s, int *nb_chars);
void	ft_putchar(char c, int *nb_chars);
void	ft_putnbr(int n, int *res);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_print_base(unsigned int nbr, int uper, int *res);
void	convert_to_pointer(unsigned long long ptr, int *nb_chars);
size_t	ft_getlen(unsigned long num, unsigned long base);
char	*convert_to_hex(unsigned long ptr, int upper);
void	ft_put_unsigned_nbr(unsigned int n, int *nb);
void	ft_put_format(const char *str, int *res, int *pos);
int		ft_is_specifier(char c);
int		ft_put_percent(int nbtimes);
void	*ft_memset(void *b, int c, size_t len);
int		ft_putspace(int nb_spaces);
int 	ft_putzeroes(int nb_zeroes);
#endif
