/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:27:20 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/28 22:40:22 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/ft_printf.h"
#include <limits.h>
/*
typedef struct format_int
{
	char format;
	int	percision;
	int	minus;
	int zero;

}t_info;
*/
static int	do_operation(const char *format, va_list args, int *res, int *pos)
{
	t_info *temp;
	//int i;

	temp = (t_info *)(malloc(sizeof(t_info)));
	ft_set_struct(temp);
	if (*format == 'p')
		convert_to_pointer(va_arg(args, long long), res, temp, NULL);
	if (*format == 'c')
		ft_putchar(va_arg(args, int), res, temp, NULL);
	if (*format == 's')
		ft_putstr(va_arg(args, char *), res, temp, NULL);
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), res, temp, ft_putspace);
	if (*format == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int), res, temp, NULL);
	if (*format == 'x')
		ft_print_base(va_arg(args, unsigned int),ft_configure(res), temp, NULL);
	if (*format == 'X')
		ft_print_base(va_arg(args, unsigned int), res, temp, NULL);
	free(temp);
	temp = NULL;
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
	t_info	*f_info;
	int		i;
	int		result;
	int		skiped;

	i = 0;
	result = 0;
	va_start(args, placeHolders);
	while (placeHolders[i])
	{
		f_info = (t_info *)(malloc(sizeof(t_info)));
		ft_set_struct(f_info);
		if (placeHolders[i] == '%')
			skiped = exception(&placeHolders[i + 1], f_info);
		if (placeHolders[i] == '%' && skiped != -1)
		{
			i += skiped;
			ft_set_format(args, f_info, &result);
		}
		else if (placeHolders[i] == '%')
			result += do_operation(&placeHolders[++i], args, &result, &i);
		else
			result += write(1, &placeHolders[i], 1);
		i++;
		free(f_info);
		f_info = NULL;
	}
	va_end(args);
	return (result);
}
/*
int main(void)
{	
	ft_printf("%+d\n", 0);
	printf("%+d", 0);
	return (0);
}*/
