/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:48:13 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 23:52:10 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_printnbr(int n, int *nb)
{
	char	t;

	if (nb < 0)
	{
		n *= -1;
		*nb += write(1, "-", 1);
	}
	if (n > 9)
		ft_printnbr(n / 10, nb);
	t = (n % 10) + '0';
	*nb += write(1, &t, 1);
}

void	put_minint(t_info *info, int *nb, int (*f)())
{
	int	i;
	int	perc;

	perc = info->percision;
	i = 0;
	if (info->minus)
	{
		*nb += write(1, "-2147483648", 11);
		i += f(perc - 11);
	}
	else
	{
		i += f(perc - 11);
		*nb += write(1, "-2147483648", 11);
	}
	*nb += i;
}

int	ft_put_negative(int *n, int *nb, t_info *info)
{
	int	perc;
	int	i;

	i = 0;
	perc = info->percision;
	*n *= -1;
	info->len += 1;
	if (!(info->minus) && !(info->zero))
		i += ft_putspace(perc - info->len);
	*nb += write(1, "-", 1);
	info->flag = 0;
	return (i);
}

int	handle_pecision(int n, int *nb, int (*f)(), t_info *info)
{
	int	i;

	i = 0;
	if (info->minus)
	{	
		ft_printnbr(n, nb);
		i += f(info->percision - info->len);
	}
	else
	{
		if (info->flag || (info->zero))
			i += f(info->percision - info->len);
		ft_printnbr(n, nb);
	}
	return (i);
}

void	ft_putnbr(int n, int *nb, t_info *info, int (*f)())
{
	int	perc;
	int	i;

	i = 0;
	perc = put_space_plus(n, nb, info);
	if (n < 0)
	{
		info->len = ft_getlen(-n, 10);
		if (n != -2147483648)
			i = ft_put_negative(&n, nb, info);
		else
			return (put_minint(info, nb, f));
	}
	else
		info->len = ft_getlen(n, 10);
	if (info->percision)
	{
		*nb += i + handle_pecision(n, nb, f, info);
		return ;
	}
	ft_printnbr(n, nb);
	*nb += i;
}
