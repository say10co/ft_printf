/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:07:57 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/26 20:37:03 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_dot(const char *str, t_info *info)
{
	int p;
	p = ft_get_percision(str,info);
	info->format = str[p];
	return (p);
}
