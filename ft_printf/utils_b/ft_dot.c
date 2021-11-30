/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:07:57 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 23:51:25 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_dot(const char *str, t_info *info)
{
	int	p;

	p = 0;
	if (!info->format)
	{	
		p = ft_get_percision(str, info);
		info->format = str[p];
	}
	return (p);
}

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

int	put_space_plus(int n, int *nb, t_info *info)
{
	if (n >= 0 && info->space)
		*nb += write(1, " ", 1);
	if (n >= 0 && info->plus)
		*nb += write(1, "+", 1);
	return (info->percision);
}
