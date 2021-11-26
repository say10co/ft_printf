/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:35:45 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 09:50:42 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "./includes/ft_printf.h"

static int	do_operation(const char *format, va_list args, int *res, int *pos)
{
	if (*format == 'p')
		convert_to_pointer(va_arg(args, long long), res);
	if (*format == 'c')
		ft_putchar(va_arg(args, int), res);
	if (*format == 's')
		ft_putstr(va_arg(args, char *), res);
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), res);
	if (*format == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int), res);
	if (*format == 'x')
		ft_print_base(va_arg(args, unsigned int), 0, res);
	if (*format == 'X')
		ft_print_base(va_arg(args, int), 1, res);
	if (*format == '%')
	{
		ft_put_format(format, res, pos);
		return (0);
	}
	return (0);
}

int	ft_printf(const char *placeHolders, ...)
{
	va_list	args;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start(args, placeHolders);
	while (placeHolders[i])
	{
		if (placeHolders[i] == '%' && ft_is_specifier(placeHolders[i + 1]))
			result += do_operation(&placeHolders[++i], args, &result, &i);
		else
			result += write(1, &placeHolders[i], 1);
		i++;
	}
	va_end(args);
	return (result);
}
