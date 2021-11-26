/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrU.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:30:40 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/24 21:38:26 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_put_unsigned_nbr(unsigned int n, int *nb)
{
	char	t;

	if (n > 9)
		ft_put_unsigned_nbr(n / 10, nb);
	t = (n % 10) + '0';
	*nb += write(1, &t, 1);
}
