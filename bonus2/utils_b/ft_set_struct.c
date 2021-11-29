/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:40:34 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 23:50:02 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_set_struct(t_info *strct)
{
	strct->format = 0;
	strct->percision = 0;
	strct->minus = 0;
	strct->zero = 0;
	strct->astra = 0;
	strct->dot = 0;
	strct->min_w = 0;
	strct->hash = 0;
	strct->plus = 0;
	strct->space = 0;
	strct->flag = 1;
	strct->len = 0;
}
