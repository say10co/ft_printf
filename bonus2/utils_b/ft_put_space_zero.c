/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_space_zero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:58:46 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 03:39:43 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putspace(int nb_spaces)
{
	int	nb;

	nb = nb_spaces;
	while (nb--)
		write(1, "_", 1);
	return (nb_spaces);
}

int ft_putzeroes(int nb_zeroes)
{
	int	nb;

	nb = nb_zeroes;
	while (nb--)
		write(1, " ", 1);
	return (nb_zeroes);
}
