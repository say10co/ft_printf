/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:40:34 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/27 00:47:21 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_set_struct(t_info *strct)
{
	strct->format = 0;
	strct->percision = 0;
	strct->minus = 0;
	strct->zero = 0;
	strct->astra = 0;
	strct->dot = 0;
	strct->min_w = 0;
}
