/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:14:14 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/26 21:00:32 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
int non(int nb)
{
	return (nb * 0);
}

int *ft_configure(int *res)
{
	if (*res == 0)
		*res = -16;
	else
		*res = -(*res);
	return (res);
}

void ft_help(va_list args, t_info *info, int *res)
{
	char *s;
	if (info->format == 's')
	{
		s = ft_substr(va_arg(args, char *), 0, info->percision);
		ft_putstr_b(s, res, info, non);
		free(s);
	}	
	if (info->format == 'd' || info->format == 'i')
		ft_putnbr_b(va_arg(args, int), res, info, ft_putzeroes);
	if (info->format == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int), res, info, ft_putzeroes);
	if (info->format == 'X')
		ft_print_base(va_arg(args, unsigned int),res, info, ft_putzeroes);
	if (info->format == 'x')
		ft_print_base(va_arg(args, unsigned int), ft_configure(res), info, ft_putzeroes);

}	
void	ft_set_format(va_list args, t_info *format, int *res)
{
	int	(*f)();
	
	f = &ft_putspace;
	if (format->dot)
	{
		ft_help(args, format, res);
		return ;
	}
	if (format->zero && !(format->minus)) // means atoi found zero
		f = &ft_putzeroes;
	if (format->format == 'c')
		ft_putchar(va_arg(args, int), res, format, f);
	if (format->format == 's')
		ft_putstr(va_arg(args, char *), res,  format, f);
	if (format->format == 'd' || format->format == 'i')
		ft_putnbr(va_arg(args, int), res, format, f);
	if (format->format == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int), res, format, f);
	if (format->format == 'X')
		ft_print_base(va_arg(args, unsigned int),res, format, f);
	if (format->format == 'x')
		ft_print_base(va_arg(args, unsigned int),ft_configure(res), format, f);
	if (format->format == 'p')
		convert_to_pointer(va_arg(args, long long), res, format, f);
		
	//return (0);
}
