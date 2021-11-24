/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:29:42 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/24 18:43:34 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

int ft_custom_atoi(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] == '-')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] == '.')
	{
		i++;
		return (ft_atoi(&str[i]));
	}
	return (i);
}
/*
int main()
{
	printf("%d\n", ft_custom_atoi("--0005d"));
	printf("%0.5d", 42);
	return (0);
}	
*/
