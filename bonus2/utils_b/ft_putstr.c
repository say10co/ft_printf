/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:08:48 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 05:02:07 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int ft_printstr(char *str)
{
	int	o;

	o = 0;
	while (str[o])
	{
		write(1, &str[o], 1);
		o++;
	}
	return (o);
}

void	ft_putstr(char *s, int *nb_chars, t_info *info)
{
	int	i;
	int prec;
	
	if (!s)
	{
		*nb_chars += write(1, "(null)", 6);
		return ;
	}
	if (info->percision)
	{
		prec = info->percision;
		if (info->minus)
		{
			i += ft_printstr(s);
			i += ft_putspace(prec - ft_strlen(s));
		}
		else
		{	
			i += ft_putspace(prec - ft_strlen(s));
			i += ft_printstr(s);
		}
		*nb_chars += i;
	   	return ;
	}
	i = ft_printstr(s);
	*nb_chars += i;
}
