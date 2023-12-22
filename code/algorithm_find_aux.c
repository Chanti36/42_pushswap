/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_find_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:44:07 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/04 12:06:24 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_move(int num, t_list *stack, int *minmax_val, int *minmax_num)
{
	int	iter;

	iter = 0;
	if ((num < stack->content && \
		num > ft_lstlast(stack)->content) && \
		*minmax_val > ft_lstlast(stack)->content)
	{
		*minmax_val = ft_lstlast(stack)->content;
		*minmax_num = iter;
	}
	++iter;
	while (stack->next)
	{
		if ((num > stack->content && \
			num < stack->next->content) && \
			*minmax_val > stack->content)
		{
			*minmax_val = stack->next->content;
			*minmax_num = iter;
		}
		++iter;
		stack = stack->next;
	}
}

int	final_val(int val_b, int val_a)
{
	if (val_b > 0 && val_a > 0)
	{
		if (val_b > val_a)
			return (val_b);
		else
			return (val_a);
	}
	if (val_b < 0 && val_a < 0)
	{
		if (val_b < val_a)
			return (val_b);
		else
			return (val_a);
	}
	if (val_a < 0)
		val_a *= -1;
	if (val_b < 0)
		val_b *= -1;
	return (val_b + val_a);
}

int	val_set_b(t_list *stack_b, int index)
{
	int	size_b;
	int	val_b;

	size_b = stack_size(stack_b);
	if (index > size_b / 2)
		val_b = -size_b + index;
	else
		val_b = index;
	return (val_b);
}

int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		++size;
	}
	return (size);
}

int	get_index_value(int index, t_list *stack)
{
	while (index > 0 && stack)
	{
		stack = stack->next;
		--index;
	}
	return (stack->content);
}
