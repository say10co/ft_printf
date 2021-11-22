/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getLen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:44:48 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/22 18:30:30 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_getLen(unsigned long num, unsigned long base)
{
	size_t	len;
	
	len = 0;
	if (!num)
		return (1);
	while (num)
	{
		len++;
		num /= base;
	}
	return (len);
}
