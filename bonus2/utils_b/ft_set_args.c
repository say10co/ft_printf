/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:14:14 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 06:20:57 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_set_format(va_list args, t_info *format, int *res)
{

	if (format->format == 'c')
		ft_putchar(va_arg(args, int), res, format);

	if (format->format == 's')
		ft_putstr(va_arg(args, char *), res,  format);
	if (format->format == 'd' || format->format == 'i')
		ft_putnbr(va_arg(args, int), res, format);
	if (format->format == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int), res, format);
	if (format->format == 'X')
		ft_print_base(va_arg(args, unsigned int), 1, res, format);
	if (format->format == 'x')
		ft_print_base(va_arg(args, unsigned int), 0, res, format);
	if (format->format == 'p')
		convert_to_pointer(va_arg(args, long long), res, format);
	return (0);
}
