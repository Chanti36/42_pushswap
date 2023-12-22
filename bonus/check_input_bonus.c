/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:01:29 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/05 11:10:40 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	check_movement(char *movement, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(movement, "sa\n", 3))
		swap(stack_a);
	else if (!ft_strncmp(movement, "sb\n", 3))
		swap(stack_b);
	else if (!ft_strncmp(movement, "ss\n", 3))
		swap_a_b(stack_a, stack_a);
	else if (!ft_strncmp(movement, "pa\n", 3))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp(movement, "pb\n", 3))
		push_b(stack_a, stack_b);
	else if (!ft_strncmp(movement, "ra\n", 3))
		rotate(stack_a);
	else if (!ft_strncmp(movement, "rb\n", 3))
		rotate(stack_b);
	else if (!ft_strncmp(movement, "rr\n", 3))
		rotate_a_b(stack_a, stack_a);
	else if (!ft_strncmp(movement, "rra\n", 4))
		reverse_rotate(stack_a);
	else if (!ft_strncmp(movement, "rrb\n", 4))
		reverse_rotate(stack_b);
	else if (!ft_strncmp(movement, "rrr\n", 4))
		reverse_rotate_a_b(stack_a, stack_b);
	else
		return (1);
	return (0);
}
