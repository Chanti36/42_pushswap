/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:40:45 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/04 10:11:31 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa sb
void	swap( t_list **stack, char name)
{
	t_list	*p;

	p = NULL;
	if (*stack && (*stack)->next)
	{
		if (name == 'a' || name == 'b')
		{
			if (name == 'a')
				write(1, "sa", 2);
			if (name == 'b')
				write(1, "sb", 2);
			write(1, "\n", 1);
		}
		p = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		p->next = *stack;
		*stack = p;
	}
}

//ss
void	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 's');
	swap(stack_b, 's');
	write(1, "ss", 2);
	write(1, "\n", 1);
}

//pa
void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;

	p = NULL;
	if (!(*stack_b))
		return ;
	write(1, "pa", 2);
	write(1, "\n", 1);
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
	write(1, "pb", 2);
	write(1, "\n", 1);
	p = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, p);
}
