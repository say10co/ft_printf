/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:08:48 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 18:07:23 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printstr(char *str)
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

int	lead_spaces(char *s, t_info *info)
{
	int	nb_spaces;
	int	i;

	i = 0;
	nb_spaces = (info->percision) - ft_strlen(s);
	if (info->minus)
	{
		i += ft_putspace(nb_spaces);
		i += ft_printstr(s);
	}
	else
	{
		i += ft_printstr(s);
		i += ft_putspace(nb_spaces);
	}
	return (i);
}

void	null_str(t_info *info, int (*f)(), int *nb_chars)
{
	int	i;
	int	prec;

	i = 0;
	prec = 0;
	if (info->percision)
	{
		prec = info->percision;
		if (info->minus)
		{
			*nb_chars += write(1, "(null)", 6);
			i += f(prec - 6);
		}
		else
		{
			i += f(prec - 6);
			*nb_chars += write(1, "(null)", 6);
		}
		*nb_chars += i;
		return ;
	}
	*nb_chars += write(1, "(null)", 6);
	return ;
}

void	ft_putstr(char *s, int *nb_chars, t_info *info, int (*f)())
{
	int	prec;

	if (info->min_w)
		*nb_chars += lead_spaces(s, info);
	if (!s)
		return (null_str(info, f, nb_chars));
	if (info->percision)
	{
		prec = info->percision;
		if (info->minus)
		{
			*nb_chars += ft_printstr(s);
			*nb_chars += f(prec - ft_strlen(s));
		}
		else
		{
			*nb_chars += f(prec - ft_strlen(s));
			*nb_chars += ft_printstr(s);
		}
		return ;
	}
	*nb_chars += ft_printstr(s);
}
