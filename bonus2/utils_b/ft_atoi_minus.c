/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:31:21 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/25 01:33:18 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_minus(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == ' ')
		i++;
	return (0);
}
