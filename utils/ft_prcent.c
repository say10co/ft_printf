/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:10:14 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/23 16:48:40 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "../includes/ft_printf.h"

int	escape(const char *str, int *res)
{
	int i;
	int escape;

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
	*res += ((i + 1) / 2);
	return (-i);
}
