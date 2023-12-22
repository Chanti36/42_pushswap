/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:18:21 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/05 11:54:28 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setup_stack_b(t_list **stack, int index)
{
	int	size;

	size = stack_size(*stack);
	if (index < size / 2)
	{
		while (index > 0)
		{
			rotate(stack, 'b');
			--index;
		}
	}
	else
	{
		while (index < size && index != 0)
		{
			reverse_rotate(stack, 'b');
			++index;
		}
	}
}

void	setup_stack_a(t_list **stack, int dir_val)
{
	int	dir;

	dir = 1;
	if (dir_val < 0)
	{
		dir_val *= -1;
		dir = -1;
	}
	if (dir == 1)
	{
		while (dir_val > 0)
		{
			rotate(stack, 'a');
			--dir_val;
		}
	}
	else
	{
		while (dir_val > 0)
		{
			reverse_rotate(stack, 'a');
			--dir_val;
		}
	}
}

int	get_b_val(t_list *stack, int index)
{
	while (index > 0)
	{
		stack = stack->next;
		--index;
	}
	return (stack->content);
}

void	double_moves(int *index, int *dir_val, \
		t_list **stack_a, t_list **stack_b)
{
	int	size_b;

	size_b = stack_size(*stack_b);
	if (*index < size_b / 2 && *dir_val > 0)
	{
		while (*index > 0 && *dir_val > 0)
		{
			rotate_a_b(stack_a, stack_b);
			--*index;
			--*dir_val;
		}
	}
	else if (*index > size_b / 2 && *dir_val < 0)
	{
		while (*index < size_b && *dir_val < 0)
		{
			reverse_rotate_a_b(stack_a, stack_b);
			++*dir_val;
			++*index;
		}
	}
}

void	make_move(t_list **stack_a, t_list **stack_b, int index)
{
	int	size_a;
	int	size_b;
	int	val_b;
	int	dir_val;

	val_b = get_b_val(*stack_b, index);
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	dir_val = val_to_insert(val_b, *stack_a, size_a);
	double_moves(&index, &dir_val, stack_a, stack_b);
	setup_stack_b(stack_b, index);
	setup_stack_a(stack_a, dir_val);
	push_a(stack_a, stack_b);
}
