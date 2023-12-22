/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:22:14 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/04 10:16:30 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long int	ft_atoi(const char *str)
{
	long int	n;
	long int	sign;

	n = 0;
	sign = 1;
	while ((*str == '\t' || *str == '\n' || *str == '\v') || \
		(*str == '\f' || *str == '\r' || *str == ' '))
	{
		++str;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += *str - 48;
		++str;
	}
	n *= sign;
	return (n);
}
