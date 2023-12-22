/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:30:55 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/04 13:04:29 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_two(t_list **stack_a)
{
	swap(stack_a, 'a');
}

void	order_three(t_list **stack_a)
{
	if ((*stack_a)->content < (*stack_a)->next->next->content && \
		(*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if ((*stack_a)->content < (*stack_a)->next->content && \
		(*stack_a)->content > (*stack_a)->next->next->content)
		reverse_rotate(stack_a, 'a');
	else if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_a)->content < (*stack_a)->next->next->content)
		swap(stack_a, 'a');
	else if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_a)->next->content < (*stack_a)->next->next->content)
		rotate(stack_a, 'a');
	else if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		swap(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
}

void	order_four(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->content > (*stack_a)->next->content || \
	(*stack_a)->content > (*stack_a)->next->next->content || \
	(*stack_a)->content > (*stack_a)->next->next->next->content)
		rotate(stack_a, 'a');
	push_b(stack_a, stack_b);
	order_three(stack_a);
	push_a(stack_a, stack_b);
}

void	order_five(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	order_three(stack_a);
	if ((*stack_b)->content > (*stack_b)->next->content)
		swap(stack_b, 'b');
	if ((*stack_b)->content < (*stack_a)->content)
		push_a(stack_a, stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->content < (*stack_a)->content && \
			(*stack_b)->content > ft_lstlast(*stack_a)->content)
			push_a(stack_a, stack_b);
		else if (ft_lstlast(*stack_a)->content > (*stack_a)->content && \
			ft_lstlast(*stack_a)->content < (*stack_b)->content)
			push_a(stack_a, stack_b);
		rotate(stack_a, 'a');
	}
	while (ft_lstlast(*stack_a)->content < (*stack_a)->content)
		rotate(stack_a, 'a');
}

void	order(t_list **stack_a, t_list **stack_b)
{
	int	nums;

	nums = ft_lstsize(*stack_a);
	if (check_order(stack_a) == 0 || nums < 2)
		return ;
	if (nums == 2)
		order_two(stack_a);
	else if (nums == 3)
		order_three(stack_a);
	else if (nums == 4)
		order_four(stack_a, stack_b);
	else if (nums == 5)
		order_five(stack_a, stack_b);
	else
		order_algorithm(stack_a, stack_b);
}
