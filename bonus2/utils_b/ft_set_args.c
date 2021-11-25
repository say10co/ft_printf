/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:14:14 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 03:53:43 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_set_format(va_list args, t_info *format, int *res)
{

	if (format->format == 'c')
		ft_putchar(va_arg(args, int), res, format);
	return (0);
}
