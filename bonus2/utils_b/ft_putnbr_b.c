/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:07:02 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/26 19:48:27 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"


void	ft_putstr_normal(char *s, int *nb)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] && ++i)
		*nb += write(1, &s[i - 1], 1);
}

void lead_zero(char *to_print, int *nb,  t_info *info, int (*f)())
{
	size_t len;

	len = ft_strlen(to_print);
	*nb += f(info->percision - len);
	ft_putstr_normal(to_print, nb);

}

void	ft_putnbr_b(int n,  int *nb, t_info *info, int (*f)())
{
	char *to_print;

	if (info->percision == -42 && !n)
		return ;
	if (n < 0)
	{	
		*nb += write(1, "-", 1);
		if (n == -2147483648)
			to_print = ft_strdup("2147483648");
		else
			to_print = ft_itoa(-n);
	}
	else
		to_print = ft_itoa(n);
	lead_zero(to_print, nb, info, f);
	free(to_print);
}
