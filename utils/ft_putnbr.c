/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:48:13 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/23 13:39:10 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_putnbr(int n, int *nb)
{
	char		t;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			*nb = *nb +  write(1, "-2147483648", 11);
			return (0);
		}
		else
		{
			n *= -1;
			*nb = *nb + write(1, "-", 1);
		}
	}
	if (n > 9)
		ft_putnbr(n / 10, nb);
	t = (n % 10) + '0';
	*nb += write(1, &t, 1);
	return (*nb);
}
