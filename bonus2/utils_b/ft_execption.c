/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execption.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:46:58 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 09:09:58 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_get_percision(const char *str, int *percision)
{
	unsigned long		result;
	int					i;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			result = result * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	*percision = result;
	return (i);
}

int exception(const char *str, t_info *strct)
{
	int i;
	int except;
	int	skiped;

	except = 1;
	i = 0;
	while (str[i] == '%')
		i++;
	ft_put_percent((i + 1) / 2);
	if ((i + 1) %  2 == 0)
		return (0);
	while (str[i] == ' ' || str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
		{
			except = 1;
			strct->minus = 1;
		}
		if (str[i] == '0')
			strct->zero = 1;
		i++;
	}
	if (!except && ft_is_specifier(str[i]))
		return (-1);
	skiped = ft_get_percision((const char *)&str[i], &(strct->percision));
	if (ft_is_specifier(str[i + skiped]))
	{
		strct->format  = str[i + skiped];
		return (i + skiped + 1);
	}
	//else if (str[i + skiped] == '.' && str[i + skiped + 1] == 'f')
	//	ft_put_float(ft_get_percision(str + skiped + 1));
	
	return(-1);	
}

