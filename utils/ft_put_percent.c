/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:22:48 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/23 16:37:25 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_put_percent(int nbtimes)
{
	int i = 0;
	while (i < nbtimes)
	{
		write(1, "%d", 1);
		i++;
	}		
	return (nbtimes);
}
