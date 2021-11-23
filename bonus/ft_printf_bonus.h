#ifndef FT_PRINTF_H
# define FT_PRINTF_H
	
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

int		ft_printf(const char *placeHolders, ...);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n, int *res);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_print_base(unsigned int nbr, int uper, int *res);
int		convert_to_pointer(unsigned long ptr);
size_t	ft_getLen(unsigned long num, unsigned long base);
char	*convert_to_hex(unsigned long ptr, int upper);
int		ft_putnbrU(unsigned int n, int *nb);
int		escape(const char *str, int *res, va_list args);
int		ft_is_specifier(char c);
int		ft_put_percent(int nbtimes);
int		ft_custom_atoi(char *str);

#endif
