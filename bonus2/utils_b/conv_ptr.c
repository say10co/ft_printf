/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:43:19 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 06:28:43 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	conver_pointer(unsigned long long ptr, int *nb_chars)
{
	char		*radix;
	char		*result;
	size_t		len;

	radix = "0123456789abcdef";
	len = ft_getlen(ptr, 16);
	result = (char *)(calloc(len, sizeof(char)));
	if (!result)
		return ;
	*nb_chars += ft_printstr("0x");
	while (len > 0)
	{
		len--;
		result[len] = radix[ptr % 16];
		ptr /= 16;
	}
	*nb_chars += ft_printstr(result);
	free(result);
}

void	convert_to_pointer(unsigned long long ptr, int *nb_chars, t_info *info)
{
	int perc;
	int	len;
	int	i;

	len = ft_getlen(ptr, 16) + 2;
	i = 0;
	if (info->percision)
	{
		perc = info->percision ;
		if (info->minus)
		{
			conver_pointer(ptr, nb_chars);
			i += ft_putspace(perc - len);
		}
		else
		{
			i += ft_putspace(perc - len);
			conver_pointer(ptr, nb_chars);
		}
		*nb_chars += i;
		return ;
	}
	conver_pointer(ptr, nb_chars);
	*nb_chars += i;
	
}
