/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:10:14 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/23 19:10:30 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "ft_printf_bonus.h"

int	escape(const char *str, int *res, va_list args)
{
	int i;
	int escape;
	char fs;

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
		return (i - 1);
	
	}
	else 
	{
		fs = ft_get_format(str[i]);
		if (fs == 'f')
			*res += ft_precision(ft_custom_atoi, args);
			
		
		if (ft_custom_atoi(str))

	*res += ((i + 1) / 2);
	return (-i);
}
