/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:48:13 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 22:50:14 by adriouic         ###   ########.fr       */
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

int	getflaf(int i)
{
	if (i >= 0)
		return (0);
	return (1);
}

int	put_space_plus(int n, int *nb, t_info *info)
{
	if (n >= 0 && info->space)
		*nb += write(1, " ", 1);
	if (n >= 0 && info->plus)
		*nb += write(1, "+", 1);
	return (info->percision);
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

int	ft_put_negative(int *n, int *nb, t_info *info, int	*len)
{
	int perc;
	int	i;

	i = 0;
	perc = info->percision;
	*n *= -1;
	*len += 1;
	if (!(info->minus) && !(info->zero))
		i += ft_putspace(perc - *len);
	*nb += write(1, "-", 1);
	return (i);
}

void	ft_putnbr(int n, int *nb, t_info *info, int (*f)())
{
	int	perc;
	int	len;
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	perc = put_space_plus(n, nb, info);
	if (n < 0)
	{
		len = ft_getlen(-n, 10);
		if (n != -2147483648)
		{
			i = ft_put_negative(&n, nb, info, &len);
			/*
			n *= -1;
			len = ft_getlen(n, 10);
			len++;
			if (!(info->minus) && !(info->zero))
				i += ft_putspace(perc - len);
			*nb += write(1, "-", 1);*/
			flag = 0;
		}
		else
			return (put_minint(info, nb, f));
	}
	else
		len = ft_getlen(n, 10);
	if (info->percision)
	{
		if (info->minus)
		{	
			ft_printnbr(n, nb);
			i += f(perc - len);
		}
		else
		{
			if (flag || (info->zero))
				i += f(perc - len);
			ft_printnbr(n, nb);
		}
		*nb += i;
		return ;
	}
	ft_printnbr(n, nb);
	*nb += i;
}
