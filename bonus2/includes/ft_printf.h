/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:23:55 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 04:01:59 by adriouic         ###   ########.fr       */
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
	int astra;
	int	dot;
	int	min_w;
	int	hash;
	int	space;
	int	plus;

}t_info;

int		ft_printf(const char *placeHolders, ...);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s, int *nb_chars, t_info *info, int (*f)());
int		ft_putchar(char c, int *nb_chars, t_info *info, int (*f)());
void	ft_putnbr(int n, int *nb, t_info *info, int (*f)());
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_print_base(unsigned int nbr, int *res, t_info *info, int (*f)());
void	to_p(unsigned long long ptr, int *nb_chars, t_info *info, int (*f)());
size_t	ft_getlen(unsigned long num, unsigned long base);
char	*convert_to_hex(unsigned long ptr, int upper);
void	ft_put_unsigned(unsigned int n, int *nbr, t_info *info, int (*f)());
void	ft_put_format(const char *str, int *res, int *pos);
int		ft_is_specifier(char c);
int		ft_put_percent(int nbtimes);
void	*ft_memset(void *b, int c, size_t len);
int		exception(const char *sr, t_info *strct);
int		ft_putspace(int nb_spaces);
int 	ft_putzeroes(int nb_zeroes);
void	ft_set_struct(t_info *strct);
void	ft_set_format(va_list args, t_info *format, int *res);
int 	ft_printstr(char *str);
int		ft_get_percision(const char *str, t_info *format);
int		ft_dot(const char *str, t_info *format);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	ft_putnbr_b(int n,  int *nb, t_info *info, int (*f)());
char	*ft_itoa(int nbr);
int		ft_isdigit(int c);
int		ft_putstr_normal(char *s, int *nb);
void	ft_putstr_b(char *to_print, int *res, t_info *info, int (*f)());
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		*configure(int *res);
int		deconfigure(int *res);
int		get_perc(const char *str, t_info *info, int i);
int		hash(int i, int upper, int *res, int n);
#endif
