/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:56:47 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/04 17:00:05 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//ra rb
void	rotate(t_list **stack)
{
	t_list	*p;

	p = NULL;
	if (!(*stack) || !(*stack)->next)
		return ;
	p = *stack;
	*stack = (*stack)->next;
	ft_lstlast(*stack)->next = p;
	p->next = NULL;
}

//r
void	rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

//rra rrb
void	reverse_rotate(t_list **stack)
{
	t_list	*p;
	t_list	*s;

	p = NULL;
	if (!(*stack) || !(*stack)->next)
		return ;
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
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
