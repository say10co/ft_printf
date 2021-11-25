/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:06:16 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 04:12:19 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_putchar(char c, int *nb_chars, t_info *info)
{
	int prec;
	int len;
	int	i;

	i = 0;
	if (info->percision)
	{	
		prec = info->percision ;
		if (info->minus)
		{
			i += write(1, &c, 1);
			i += ft_putspace(prec - 1);
		}
		else
		{
			i += ft_putspace(prec -1);
			i += write(1, &c, 1);
		}
		*nb_chars += i;
		return (i);
	}
	*nb_chars += write(1, &c, 1);
	return (0);
}
