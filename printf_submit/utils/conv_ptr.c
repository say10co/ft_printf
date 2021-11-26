/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:43:19 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/24 23:14:03 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	convert_to_pointer(unsigned long long ptr, int *nb_chars)
{
	char		*radix;
	char		*result;
	size_t		len;

	radix = "0123456789abcdef";
	len = ft_getlen(ptr, 16);
	result = (char *)(calloc(len, sizeof(char)));
	if (!result)
		return ;
	ft_putstr("0x", nb_chars);
	while (len > 0)
	{
		len--;
		result[len] = radix[ptr % 16];
		ptr /= 16;
	}
	ft_putstr(result, nb_chars);
	free(result);
}
