/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:35:45 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/24 19:00:09 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf_bonus.h"

static int do_operation(const char *format, va_list args, int *res, int *i)
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
		t = escape(format, res, args);
		//if (t > 0)
			//return (-t);
		else
		{
			ft_put_percent((-t + 1) / 2);
			return (t);
		}
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
			x = do_operation(&placeHolders[i + 1], args, &result, &i);
			//if (x < 0)
				//i += -x;
			else
			{
				result += x;
				i += 1;
			}
		}
		else
			result += write(1, &placeHolders[i], 1);
		i++;
	}
	va_end(args);
	return (result);}


int main()
{
	int x = 0;
	int y = 0;   
	
	printf(" %d\n", printf("%%%.1f", 42.13));
	printf(" %d\n", ft_printf("%%%.1f", 42.13));

	//printf("%d\n", printf("%%%%%%%%%%%%d\n", 42));
	//printf("%d\n", ft_printf("%%%%%%%%%%%%d\n", 42));
	//

	return (0);
}
