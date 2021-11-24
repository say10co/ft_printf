/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:10:14 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/24 19:00:06 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "ft_printf_bonus.h"

int	escape(const char *str, int *res, va_list arg, int *pos)
{
	int i;
	int escape;
	char fs;
	int n;

	escape = 1;
	i = 0;
	while (str[i] == '%')
	{
		escape = !escape;
		i++;
	}
	if (escape && ft_is_specifier(str[i]))
	{
		*res += ft_put_percent(i / 2);
		*pos += (i - 1); 
		return (0);
	
	}
	else if (1)
	{
		ft_put_percent(++i / 2);
		//fs = ft_get_format((str[i]));
		fs = 'f';
		if (fs == 'f')
		{
			
			n = ft_precision(ft_custom_atoi((char *)&str[i]), args);
			while (fs != str[i])
				i++;
			*res += n;
			*pos = (i + 1);
			return (0);
		}
		//if (ft_custom_atoi((char *)&str))

		*res += ((i + 1) / 2);
	}
	return (-i);
}
