/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:24:02 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/30 04:01:10 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

char	*form_null(t_info *info, int *flag)
{
	char	*to_print;

	to_print = ft_substr("(null)", 0, info->percision);
	*flag = 1;
	return (to_print);
}

char	*zeros_zero(int nb)
{	
	int		i;
	char	*re;

	i = 0;
	re = (char *)malloc(nb * sizeof(char));
	while (i < nb)
	{
		re[i] = '0';
		i++;
	}
	return (re);
}

void	ft_putstr_b(char *to_print, int *res, t_info *info, int (*f)())
{
	int		flag;
	int		len;
	int		diff;
	char	*zeros;

	flag = 0;
	if (info->percision == -42)
		return ;
	if (!to_print)
		to_print = form_null(info, &flag);
	if (info->min_w)
	{
		len = ft_strlen(to_print);
		diff = info->percision - len;
		if (info->percision > len)
		{
			zeros = zeros_zero(diff);
			to_print = ft_strjoin(zeros, to_print);
			free(zeros);
			flag = 1;
		}
	}
	ft_putstr(to_print, res, info, f);
	if (flag)
		free(to_print);
}
