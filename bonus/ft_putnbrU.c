/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrU.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:30:40 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/23 13:39:24 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_putnbrU(unsigned int n, int *nb)
{
	char			t;

	if (n > 9)
		ft_putnbrU(n / 10, nb);
	t = (n % 10) + '0';
	*nb += write(1, &t, 1);
	return (*nb);
}