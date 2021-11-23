/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:43:19 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/23 13:48:09 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../includes/ft_printf.h"

static unsigned long mod(unsigned long a, unsigned long b)
{
	long result;

	result = a % b;
	if (result < 0)
		return (-result);
	return (result);
}

int	convert_to_pointer(unsigned long ptr)
{
	char		*radix;
	char		*result;
	char		*j;
	size_t		len;
	int			res;

	res = 0;	
	radix = "0123456789abcdef";
	len = ft_getLen(ptr, 16);
	result = (char *)(calloc(len, sizeof(char)));
	if (!result)
		return (0);
	while (len > 0)
	{
		len--;
		result[len] = radix[mod(ptr, 16)];
		ptr /= 16;
	}
	j = ft_strjoin("0x", result);
	res = ft_putstr(j);
	//printf("r %c\n", result[9]);
	free(j);
	free(result);
	return (res);

}
