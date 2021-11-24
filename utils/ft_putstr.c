/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:08:48 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/24 20:54:46 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_putstr(char *s, int *nb_chars)
{
	int	i;

	if (!s)
	{
		*nb_chars += write(1, "(null)", 6);
		return ;
	}
	i = 0;
	while (s[i] && ++i)
		write(1, &s[i - 1], 1);
	*nb_chars += i;
}
