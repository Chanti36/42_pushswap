/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:41:15 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/04 09:48:47 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ra rb
void	rotate(t_list **stack, char name)
{
	t_list	*p;

	p = NULL;
	if (!(*stack) || !(*stack)->next)
		return ;
	if (name == 'a' || name == 'b')
	{
		if (name == 'a')
			write(1, "ra", 2);
		if (name == 'b')
			write(1, "rb", 2);
		write(1, "\n", 1);
	}
	p = *stack;
	*stack = (*stack)->next;
	ft_lstlast(*stack)->next = p;
	p->next = NULL;
}

//r
void	rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 's');
	rotate(stack_b, 's');
	write(1, "rr", 2);
	write(1, "\n", 1);
}

//rra rrb
void	reverse_rotate(t_list **stack, char name)
{
	t_list	*p;
	t_list	*s;

	p = NULL;
	if (!(*stack) || !(*stack)->next)
		return ;
	if (name == 'a' || name == 'b')
	{
		if (name == 'a')
			write(1, "rra", 3);
		if (name == 'b')
			write(1, "rrb", 3);
		write(1, "\n", 1);
	}
	p = ft_lstlast(*stack);
	s = *stack;
	while (s->next->next)
		s = s->next;
	s->next = NULL;
	p->next = *stack;
	*stack = p;
}

void	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, 's');
	reverse_rotate(stack_b, 's');
	write(1, "rrr", 3);
	write(1, "\n", 1);
}
