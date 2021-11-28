/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrU.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:30:40 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/28 02:49:03 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_put_unsigned(unsigned int n, int *nb)
{
	char	t;

	if (n > 9)
		ft_put_unsigned(n / 10, nb);
	t = (n % 10) + '0';
	*nb += write(1, &t, 1);
}

void ft_put_unsigned_nbr(unsigned int n, int *nbr, t_info *info, int (*f)())
{

	int perc;
	int	len;
	int	i;

	if (info->percision == -42 && !n)
		return ;
	len = ft_getlen(n, 10);
	i = 0;
	if (info->percision)
	{
		perc = info->percision ;
		if (info->minus)
		{
			ft_put_unsigned(n, nbr);
			i += f(perc - len);
		}
		else
		{
			i += f(perc - len);
			ft_put_unsigned(n, nbr);
		}
		*nbr += i;
		return ;
	}
	ft_put_unsigned(n, nbr);
	*nbr += i;
}
