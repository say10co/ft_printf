/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:14:14 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 01:15:57 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	non(int nb)
{
	return (nb * 0);
}

int	*configure(int *res)
{
	if (*res == 0)
		*res = -1337;
	else
		*res = -(*res);
	return (res);
}

void	ft_help(va_list args, t_info *info, int *res)
{
	char	*s;
	int		(*f)();

	f = ft_putzeroes;
	if (info->format == 's')
	{
		if (!(info->min_w))
		{
			s = ft_substr(va_arg(args, char *), 0, info->percision);
			ft_putstr_b(s, res, info, non);
			free(s);
		}
		else
			ft_putstr_b(va_arg(args, char *), res, info, ft_putspace);
	}	
	if (info->format == 'd' || info->format == 'i')
		ft_putnbr_b(va_arg(args, int), res, info, f);
	if (info->format == 'u')
		ft_put_unsigned(va_arg(args, unsigned int), res, info, f);
	if (info->format == 'X')
		ft_print_base(va_arg(args, unsigned int), res, info, f);
	if (info->format == 'x')
		ft_print_base(va_arg(args, unsigned int), configure(res), info, f);
}

void	ft_set_format(va_list args, t_info *format, int *res)
{
	int	(*f)();

	f = ft_putspace;
	if (format->dot)
	{
		ft_help(args, format, res);
		return ;
	}
	if (format->zero && !(format->minus))
		f = &ft_putzeroes;
	if (format->format == 'c')
		ft_putchar(va_arg(args, int), res, format, f);
	if (format->format == 's')
		ft_putstr(va_arg(args, char *), res, format, f);
	if (format->format == 'd' || format->format == 'i')
		ft_putnbr(va_arg(args, int), res, format, f);
	if (format->format == 'u')
		ft_put_unsigned(va_arg(args, unsigned int), res, format, f);
	if (format->format == 'X')
		ft_print_base(va_arg(args, unsigned int), res, format, f);
	if (format->format == 'x')
		ft_print_base(va_arg(args, unsigned int), configure(res), format, f);
	if (format->format == 'p')
		to_p(va_arg(args, long long), res, format, f);
}
