/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_one_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:56:50 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/05 11:12:00 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//sa sb
void	swap( t_list **stack)
{
	t_list	*p;

	p = NULL;
	if (*stack && (*stack)->next)
	{
		p = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		p->next = *stack;
		*stack = p;
	}
}

//ss
void	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

//pa
void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;

	p = NULL;
	if (!(*stack_b))
		return ;
	p = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, p);
}

// pb
void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;

	p = NULL;
	if (!(*stack_a))
		return ;
	p = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, p);
}
