/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_percision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 01:47:17 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 01:47:25 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_get_percision(const char *str, t_info *format)
{
	unsigned long		result;
	int					i;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			result = result * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	if (!result)
	{
		if (str[i - 1] == '0' || !ft_isdigit(str[i]))
			format->percision = -42;
	}
	else
		format->percision = result;
	return (i);
}

int	get_perc(const char *str, t_info *info, int i)
{
	info->dot = 1;
	info->percision = ft_atoi(&str[i + 1]);
	i++;
	if (!(info->percision))
	{
		info->percision = -42;
		if (str[i] == '0')
		{
			info->format = str[i + 1];
			return (i + 1);
		}
		info->format = str[i];
		return (i);
	}
	i += ft_getlen(info->percision, 10);
	info->format = str[i];
	return (i);
}
