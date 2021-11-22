/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:56:51 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/23 00:26:38 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:35:45 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/22 17:54:03 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <limits.h>
int ft_is_specifier(char c)
{
	char *spec;

	spec = "cspiduxX%";
	while (*spec)
	{
		if (*spec == c)
			return (1);
		spec = spec + 1;
	}
	return (0);

}

static int do_operation(const char *format, va_list args, int *res)
{
	int t;

	if (*format == 'p')
		return (convert_to_pointer(va_arg(args, long long)));
	if ( *format == 'c')
		return (ft_putchar((va_arg(args, int))));
	if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));	
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), res);
	if (*format == 'u')
		ft_putnbrU(va_arg(args, long), res);
	if (*format == 'x')
		ft_print_base(va_arg(args, unsigned int), 0, res);
	if (*format == 'X')
		ft_print_base(va_arg(args, int), 1, res);
	if (*format == '%')
	{
		t = escape(format);
		if (t > 0)
			return (-t);
		return (write(1, "%", 1));
 	}
	return (0);

}
int	ft_printf(const char *placeHolders, ...)
{
	va_list	args;
	int		i;
	int		result;
	int 	x;

	i = 0;
	result = 0;
	va_start(args, placeHolders);
	while (placeHolders[i])
	{
		
		if (placeHolders[i] == '%' && ft_is_specifier(placeHolders[i+1]))
		{
			x = do_operation(&placeHolders[i + 1], args, &result);
			if (x < 0)
				i += -x;
			else
			{
				result += x;
				i++;
			}
		}
		else
			result += write(1, &placeHolders[i], 1);
		i++;
	}
	va_end(args);
	return (result);
}
/*
int main()
{	
	printf("%d\n", printf("%%%%%%%%%%%%d\n", 42));
	printf("%d\n", ft_printf("%%%%%%%%%%%%d\n", 42));

	return (0);
}
*/
