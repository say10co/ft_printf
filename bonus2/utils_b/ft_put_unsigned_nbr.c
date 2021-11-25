/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrU.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:30:40 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 05:47:46 by adriouic         ###   ########.fr       */
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

void ft_put_unsigned_nbr(unsigned int n, int *nbr, t_info *info)
{

	int perc;
	int	len;
	int	i;

	len = ft_getlen(n, 10);
	i = 0;
	if (info->percision)
	{
		perc = info->percision ;
		if (info->minus)
		{
			ft_put_unsigned(n, nbr);
			i += ft_putspace(perc - len);
		}
		else
		{
			i += ft_putspace(perc - len);
			ft_put_unsigned(n, nbr);
		}
		*nbr += i;
		return ;
	}
	ft_put_unsigned(n, nbr);
	*nbr += i;
}
