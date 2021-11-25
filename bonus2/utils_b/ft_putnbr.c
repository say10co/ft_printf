/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:48:13 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 10:45:26 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_printnbr(int n, int *nb)
{
	char	t;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			*nb += write(1, "-2147483648", 11);
			return ;
		}
		else
		{
			n *= -1;
			*nb += write(1, "-", 1);
		}
	}
	if (n > 9)
		ft_printnbr(n / 10, nb);
	t = (n % 10) + '0';
	*nb += write(1, &t, 1);
}

void	ft_putnbr(int n, int *nb, t_info *info, int (*f)())
{
	int perc;
	int	len;
	int	i;
	int flag; 


	perc = info->percision ;
	flag = 1;
	i = 0;
	if (n < 0)
	{
		if ( n !=  -2147483648)
		{
			n *= -1;
			len = ft_getlen(n, 10);
			len++;
			i += f(perc - len);
			*nb += write(1, "-", 1);
			flag = 0;
		}
		else
			len = 11;
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
			if (flag)
				i += f(perc - len);
			ft_printnbr(n, nb);
		}
		*nb += i;
		return ;
	}
	ft_printnbr(n, nb);
	*nb += i;
}
