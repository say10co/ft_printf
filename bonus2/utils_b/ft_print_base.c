/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:46:24 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/24 21:28:14 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

char	ft_find(int i, int uper)
{
	char	*radix;

	radix = "0123456789abcdef";
	if (uper)
		radix = "0123456789ABCDEF";
	return (radix[i]);
}

int	ft_print_base(unsigned int nbr, int uper, int *res)
{
	char	temp;

	if (nbr >= 16)
		ft_print_base(nbr / 16, uper, res);
	temp = ft_find((nbr % 16), uper);
	*res += write(1, &temp, 1);
	return (*res);
}
