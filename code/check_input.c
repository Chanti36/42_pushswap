/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:44:18 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/11/28 10:42:00 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if ((str[i] > '9' || str[i] < '0') && str[i] != ' ' && \
			str[i] != '+' && str[i] != '-')
			return (1);
		++i;
	}
	return (0);
}

int	check_sign(char *c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (c[i])
	{
		if ((c[i] >= '0' && c[i] <= '9'))
			++count;
		if ((c[i] == '-' || c[i] == '+') && i != 0)
			return (1);
		++i;
	}
	if (count > 0)
		return (0);
	return (1);
}

int	check_repeat(t_list *stack)
{
	t_list	*second;

	while (stack->next != NULL)
	{
		second = stack->next;
		while (second != NULL)
		{
			if (stack->content == second->content)
				return (1);
			second = second ->next;
		}
		stack = stack->next;
	}
	return (0);
}
