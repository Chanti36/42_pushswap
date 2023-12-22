/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:46:03 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/04 12:06:49 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_list **stack)
{
	t_list	*p;

	p = *stack;
	if (!p->next)
		return (1);
	while (p->next)
	{
		if (p->content > p->next->content)
			return (1);
		p = p->next;
	}
	return (0);
}

int	dir_to_order(t_list *stack)
{
	int	size;
	int	min_pos;
	int	min_val;

	size = 0;
	min_pos = 0;
	min_val = INT_MAX;
	while (stack)
	{
		if (stack->content < min_val)
		{
			min_val = stack->content;
			min_pos = size;
		}
		++size;
		stack = stack->next;
	}
	if (min_pos < size / 2)
		return (1);
	else
		return (-1);
}

void	order_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	move;

	while ((*stack_a)->next->next->next)
		push_b(stack_a, stack_b);
	order_three(stack_a);
	while (*stack_b)
	{
		move = find_cheapest(*stack_a, *stack_b);
		make_move(stack_a, stack_b, move);
	}
	if (dir_to_order(*stack_a) == 1)
		while ((*stack_a)->content > ft_lstlast(*stack_a)->content)
			rotate(stack_a, 'a');
	else
		while ((*stack_a)->content > ft_lstlast(*stack_a)->content)
			reverse_rotate(stack_a, 'a');
}
