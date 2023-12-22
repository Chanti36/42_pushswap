/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:47:19 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/04 16:14:54 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	val_to_insert(int num, t_list *stack, int size)
{
	int		iter;
	int		minmax_val;
	int		minmax_num;
	t_list	*save_stack;

	minmax_val = INT_MAX;
	save_stack = stack;
	best_move(num, stack, &minmax_val, &minmax_num);
	if (minmax_val == INT_MAX)
	{
		iter = 0;
		while (save_stack)
		{
			if (save_stack->content < minmax_val)
			{
				minmax_val = save_stack->content;
				minmax_num = iter;
			}
			++iter;
			save_stack = save_stack->next;
		}
	}
	if (minmax_num > size / 2)
		minmax_num = -size + minmax_num;
	return (minmax_num);
}

int	order_value(t_list *stack_a, t_list *stack_b, int index)
{
	int	val_b;
	int	val_a;
	int	size_a;
	int	index_val;

	val_b = val_set_b(stack_b, index);
	size_a = stack_size(stack_a);
	index_val = get_index_value(index, stack_b);
	val_a = val_to_insert(index_val, stack_a, size_a);
	return (final_val(val_b, val_a));
}

int	find_cheapest(t_list *stack_a, t_list *stack_b)
{
	int	index;
	int	best_index;
	int	move_val;
	int	best_move_val;
	int	size;

	index = 0;
	size = stack_size(stack_b);
	best_move_val = INT_MAX;
	while (index < size)
	{
		move_val = order_value(stack_a, stack_b, index);
		if (move_val < 0)
			move_val *= -1;
		if (move_val < best_move_val)
		{
			best_move_val = move_val;
			best_index = index;
		}
		++index;
	}
	return (best_index);
}

/*

int	val_to_insert(int num, t_list *stack, int size)
{
	int		iter;
	int		minmax_val;
	int		minmax_num;
	t_list	*save_stack;

	iter = 0;
	minmax_val = INT_MAX;
	minmax_num = INT_MAX;
	save_stack = stack;
	if (num < stack->content && \
		num > ft_lstlast(stack)->content)
	{
		if (minmax_val > ft_lstlast(stack)->content)
		{
			minmax_val = ft_lstlast(stack)->content;
			minmax_num = iter;
		}
	}
	++iter;
	while (stack->next)
	{
		if (num > stack->content && \
			num < stack->next->content)
		{
			if (minmax_val > stack->content)
			{
				minmax_val = stack->next->content;
				minmax_num = iter;
			}
		}
		++iter;
		stack = stack->next;
	}
	if (minmax_val == INT_MAX)
	{
		iter = 0;
		while (save_stack)
		{
			if (save_stack->content < minmax_val)
			{
				minmax_val = save_stack->content;
				minmax_num = iter;
			}
			++iter;
			save_stack = save_stack->next;
		}
	}
	if (minmax_num > size / 2)
		minmax_num = -size + minmax_num;
	return (minmax_num);
}

*/