/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:46:24 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 20:26:04 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

char	ft_find(int i, int uper)
{
	char	*radix;

	radix = "0123456789abcdef";
	if (uper)
		radix = "0123456789ABCDEF";
	return (radix[i]);
}

int	ft_put_base(unsigned int nbr, int uper, int *res)
{
	char	temp;

	if (nbr >= 16)
		ft_put_base(nbr / 16, uper, res);
	temp = ft_find((nbr % 16), uper);
	*res += write(1, &temp, 1);
	return (*res);
}

int	deconfigure(int *res)
{
	if (*res < 0)
	{
		if (*res == -1337)
			*res = 0;
		else
			*res = -*res;
		return (0);
	}
	return (1);
}

void	ft_print_base(unsigned int nbr, int	*res, t_info *info, int (*f)())
{
	int	len;
	int	uper;

	uper = deconfigure(res);
	if (info->percision == -42 && !nbr)
		return ;
	len = ft_getlen(nbr, 16);
	len += hash(info->hash, uper, res, nbr);
	if (info->percision)
	{
		if (info->minus)
		{
			ft_put_base(nbr, uper, res);
			*res += f((info->percision) - len);
		}
		else
		{
			*res += f(info->percision - len);
			ft_put_base(nbr, uper, res);
		}
	}
	else
		ft_put_base(nbr, uper, res);
}
