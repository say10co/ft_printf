/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execption.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:46:58 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 02:19:51 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	decide_the_value(int i)
{
	if (!i)
		return (-2);
	return (i);
}

int	get_both(const char *str, t_info *info)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]))
	{
		info->min_w = ft_atoi(&str[i]);
		i += ft_getlen(info->min_w, 10);
		if (str[i] != '.')
		{
			info->percision = info->min_w;
			info->min_w = 0;
		}
	}
	if (str[i] == '.')
		return (get_perc(str, info, i));
	if (ft_is_specifier(str[i]))
	{
		if (!i)
		{
			info->format = str[i];
			return (0);
		}
		info->format = str[i];
	}
	return (decide_the_value(i));
}

int	ft_isflag(char c)
{
	char	*flags;
	int		i;

	i = 0;
	flags = "0 -#+";
	while (flags[i++])
	{
		if (c == flags[i])
			return (1);
	}
	return (0);
}

int	handle_percent(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '%')
		i++;
	if ((i + 1) % 2 == 0)
		return (-1);
	ft_put_percent((i + 1) / 2);
	return (i);
}

int	exception(const char *str, t_info *strct)
{
	int	i;

	i = handle_percent(str);
	if (i < 0)
		return (-1);
	while (ft_isflag(str[i]))
	{
		if (str[i] == '-')
			strct->minus = 1;
		if (str[i] == '0')
			strct->zero = 1;
		if (str[i] == '#')
			strct->hash = 1;
		if (str[i] == ' ')
			strct->space = 1;
		if (str[i] == '+')
			strct->plus = 1;
		i++;
	}
	if ((int)ft_strlen(str) == i && ft_is_specifier(str[i]))
		return (-1);
	return (get_both(&str[i], strct) + i + 1);
}
