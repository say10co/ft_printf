/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execption.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:46:58 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 00:28:38 by adriouic         ###   ########.fr       */
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
	if (ft_is_specifier(str[i]))
	{
		if (!i)
		{
			info->format = str[i];
			return (0);
		}
		info->format = str[i];
	}
	if (!i)
		return (-2);
	return (i);
}

int	exception(const char *str, t_info *strct)
{
	int	i;
	int	except;

	except = 0;
	i = 0;
	while (str[i] == '%')
		i++;
	if ((i + 1) % 2 == 0)
		return (-1);
	ft_put_percent((i + 1) / 2);
	while (str[i] == ' ' || str[i] == '-' || str[i] == '0' || str[i] == '#' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			except = 1;
			strct->minus = 1;
		}
		if (str[i] == '0')
			strct->zero = 1;
		if (str[i] == '#')
		{
			except = 1;
			strct->hash = 1;
		}
		if (str[i] == ' ')
		{
			except = 1;
			strct->space = 1;
		}
		if (str[i] == '+')
		{
			except = 1;
			strct->plus = 1;
		}
		i++;
	}
	if (!except && ft_is_specifier(str[i]))
		return (-1);
	return (get_both(&str[i], strct) + i + 1);
}
