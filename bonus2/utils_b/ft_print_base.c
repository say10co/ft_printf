/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:46:24 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 04:31:45 by adriouic         ###   ########.fr       */
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
/*
int	count_len(int nbr, int *res, int uper,  t_info *info)
{
	int	len;

	len = ft_getlen(nbr, 16);
	len += hash(info->hash, uper, res, nbr);
	return (len);
}
*/
int	init_v(int *uper, int *res, int nbr, t_info *info)
{
	int	len;
	
	len = 0;	
	*uper = deconfigure(res);
	len = ft_getlen(nbr, 16);
	len += hash(info->hash, *uper, res, nbr);
	return (len);
}

void	ft_print_base(unsigned int nbr, int	*res, t_info *info, int (*f)())
{
	int	perc;
	int	len;
	int	i;
	int	uper;

	uper = deconfigure(res);
	//init_v(&uper, res, &i, nbr);
	if (info->percision == -42 && !nbr)
		return ;
	len = ft_getlen(nbr, 16);
	len += hash(info->hash, uper, res, nbr);
	//len = init_v(&uper, res, nbr, info);
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
		//return (0);
	}
	else
		ft_put_base(nbr, uper, res);
	//return (0);
}
