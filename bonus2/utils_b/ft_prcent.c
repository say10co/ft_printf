/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:10:14 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 00:45:36 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_put_format(const char *str, int *res, int *pos)
{
	int	i;
	int	valid;

	valid = 1;
	i = 0;
	while (str[i] == '%')
	{
		valid = !valid;
		i++;
	}
	if (valid && ft_is_specifier(str[i]))
	{
		*res += ft_put_percent(i / 2);
		*pos += i - 2;
		return ;
	}
	*res += ((i + 1) / 2);
	ft_put_percent((i + 1) / 2);
	*pos += (i - 1);
}
