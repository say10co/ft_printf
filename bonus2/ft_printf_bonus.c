/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:27:20 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 03:04:35 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/ft_printf.h"

static void	do_operation(const char *format, va_list args, int *res, int *pos)
{
	t_info	*temp;

	temp = (t_info *)(malloc(sizeof(t_info)));
	ft_set_struct(temp);
	if (*format == 'p')
		to_p(va_arg(args, long long), res, temp, NULL);
	if (*format == 'c')
		ft_putchar(va_arg(args, int), res, temp, NULL);
	if (*format == 's')
		ft_putstr(va_arg(args, char *), res, temp, NULL);
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), res, temp, ft_putspace);
	if (*format == 'u')
		ft_put_unsigned(va_arg(args, unsigned int), res, temp, NULL);
	if (*format == 'x')
		ft_print_base(va_arg(args, unsigned int), configure(res), temp, NULL);
	if (*format == 'X')
		ft_print_base(va_arg(args, unsigned int), res, temp, NULL);
	free(temp);
	temp = NULL;
	if (*format == '%')
		ft_put_format(format, res, pos);
}

static int	check_ex(const char *phs, int *result, t_info *info, va_list args)
{	
	int	i;
	int	skiped;

	i = 0;
	skiped = 0;
	if (phs[i] == '%')
		skiped = exception(&phs[i + 1], info);
	else
		return (-1);
	if (skiped != -1)
	{
		ft_set_format(args, info, result);
		return (skiped);
	}
	return (-1);
}

int	ft_printf(const char *placeHolders, ...)
{
	va_list	args;
	t_info	*f_info;
	int		i;
	int		result;
	int		l;

	i = 0;
	result = 0;
	va_start(args, placeHolders);
	while (placeHolders[i])
	{
		f_info = (t_info *)(malloc(sizeof(t_info)));
		ft_set_struct(f_info);
		l = check_ex(&placeHolders[i], &result, f_info, args);
		if (l != -1)
			i += l;
		else if (placeHolders[i] == '%')
			do_operation(&placeHolders[++i], args, &result, &i);
		else
			result += write(1, &placeHolders[i], 1);
		i++;
		free(f_info);
	}
	va_end(args);
	return (result);
}
/*
int main(void)
{	
	ft_printf("%01d\n", 0);
	printf("%01d", 0);
	return (0);
}*/
