/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:10:14 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/23 00:04:04 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	escape(const char *str)
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
	if (!escape && ft_is_specifier(str[i]))
		return (i);
	return (-i);
}
