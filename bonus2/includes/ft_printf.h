/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:23:55 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 03:53:52 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
	
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct format_int
{
	char format;
	int	percision;
	int	minus;
	int zero;

}t_info;

int		ft_printf(const char *placeHolders, ...);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s, int *nb_chars);
int		ft_putchar(char c, int *nb_chars, t_info *info);
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
int		exception(const char *sr, t_info *strct);
int		ft_putspace(int nb_spaces);
int 	ft_putzeroes(int nb_zeroes);
void	ft_set_struct(t_info *strct);
int		ft_set_format(va_list args, t_info *format, int *res);

#endif
