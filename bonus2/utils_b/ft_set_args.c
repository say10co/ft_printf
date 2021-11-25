/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:14:14 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 10:26:48 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_set_format(va_list args, t_info *format, int *res)
{
	int	(*f)();

	f = &ft_putspace;
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
	{
		if (*res == 0)
			*res = -1;
		else
			*res = -(*res);
		ft_print_base(va_arg(args, unsigned int),res, format, f);
	}
	if (format->format == 'p')
		convert_to_pointer(va_arg(args, long long), res, format, f);
		
	return (0);
}
