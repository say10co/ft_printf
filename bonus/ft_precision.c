/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:12:20 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/24 18:33:16 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"
#include <stdarg.h>

int	ft_precision(int prec, va_list args)
{
	float	f;
	char	res[10];
	
	res[9] = '\0';
	f = va_arg(args, double);
	ft_ftoa(f, res, prec);
	printf("%s\n", res);
	return (ft_strlen(res));
}
