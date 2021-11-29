/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:06:16 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 00:36:10 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_putchar(char c, int *nb_chars, t_info *info, int (*f)())
{
	int	prec;
	int	i;

	i = 0;
	if (info->percision)
	{	
		prec = info->percision ;
		if (info->minus)
		{
			i += write(1, &c, 1);
			i += f(prec - 1);
		}
		else
		{
			i += f(prec -1);
			i += write(1, &c, 1);
		}
		*nb_chars += i;
		return (i);
	}
	*nb_chars += write(1, &c, 1);
	return (0);
}
