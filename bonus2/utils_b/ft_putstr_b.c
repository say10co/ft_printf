/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:24:02 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/26 20:07:02 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void ft_putstr_b(char *to_print, int *res, t_info *info, int (*f)())
{
	int flag;

	flag = 0;	
	if (info->percision == -42)
		return ;
	if (!to_print)
	{
		to_print = ft_substr("(null)", 0, info->percision);
		flag = !flag;
	}
	ft_putstr(to_print, res, info, f);
	if (flag)
		free(to_print);
}
