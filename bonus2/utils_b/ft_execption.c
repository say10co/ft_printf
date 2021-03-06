/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execption.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:46:58 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 17:59:55 by adriouic         ###   ########.fr       */
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
	while (flags[i])
	{
		if (c == flags[i])
			return (1);
		i++;
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
	int	count;

	i = handle_percent(str);
	if (i < 0)
		return (-1);
	count = i;
	while (ft_isflag(str[i++]))
	{
		if (str[i - 1] == '-')
			strct->minus = 1;
		else if (str[i - 1] == '0')
			strct->zero = 1;
		else if (str[i - 1] == '#')
			strct->hash = 1;
		else if (str[i - 1] == ' ')
			strct->space = 1;
		else if (str[i - 1] == '+')
			strct->plus = 1;
		else
			count++;
	}
	if (count == i - 1 && ft_is_specifier(str[i - 1]))
		return (-1);
	return (get_both(&str[i - 1], strct) + (i - 1) + 1);
}
