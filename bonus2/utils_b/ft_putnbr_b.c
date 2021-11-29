/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:07:02 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/29 00:43:16 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_putstr_normal(char *s, int *nb)
{
	int	i;

	(void)nb;
	if (!s)
		return (0);
	i = 0;
	while (s[i] && ++i)
		write(1, &s[i - 1], 1);
	return (i);
}

void	lead_zero(char *to_print, int *nb, t_info *info, int (*f)())
{
	size_t	len;
	int		i;
	int		sh;
	int		q;

	i = 0;
	q = 0;
	len = ft_strlen(to_print);
	if (to_print[0] == '-')
	{
		len --;
		to_print++;
		q = -1;
	}
	if ((int)len < info->min_w && info->minus)
	{
		i += f(info->percision - (int)len);
		i += ft_putstr_normal(to_print, nb);
		i += ft_putspace(info->min_w - i + q);
		*nb += i;
	}
	else if ((int)len <= info->min_w || info->min_w == 0)
	{
		sh = len;
		if (info->percision > (int)len)
			sh = info->percision;
		i += ft_putspace(info->min_w - sh);
		i += f(info->percision - len);
		i += ft_putstr_normal(to_print, nb);
		*nb += i;
	}
	else
	{
		sh = len;
		if (info->percision > (int)len)
			sh = info->percision;
		i += ft_putspace(info->min_w - sh);
		i += f(info->percision - len);
		i += ft_putstr_normal(to_print, nb);
		*nb += i;
	}
}

void	ft_putnbr_b(int n, int *nb, t_info *info, int (*f)())
{
	char	*to_print;

	if (info->percision == -42 && !n)
	{
		*nb += ft_putspace(info->min_w);
		return ;
	}
	if (n < 0)
	{	
		*nb += write(1, "-", 1);
		if (n == -2147483648)
			to_print = ft_strdup("2147483648");
		else
			to_print = ft_itoa(n);
	}
	else
		to_print = ft_itoa(n);
	lead_zero(to_print, nb, info, f);
	free(to_print);
}
