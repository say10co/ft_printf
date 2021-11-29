/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:46:24 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 00:31:43 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	hash(int i, int upper, int *res, int n)
{
	if (i && upper && n)
	{
		*res += 2;
		return (write(1, "0X", 2));
	}
	else if (i && !upper && n)
	{
		*res += 2;
		return (write(1, "0x", 2));
	}
	return (0);
}

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

int	ft_print_base(unsigned int nbr, int	*res, t_info *info, int (*f)())
{
	int	perc;
	int	len;
	int	i;
	int	uper;

	uper = deconfigure(res);
	if (info->percision == -42 && !nbr)
		return (0);
	len = ft_getlen(nbr, 16);
	len += hash(info->hash, uper, res, nbr);
	i = 0;
	if (info->percision)
	{
		perc = info->percision ;
		if (info->minus)
		{
			ft_put_base(nbr, uper, res);
			i += f(perc - len);
		}
		else
		{
			i += f(perc - len);
			ft_put_base(nbr, uper, res);
		}
		*res += i;
		return (0);
	}
	ft_put_base(nbr, uper, res);
	return (0);
}
