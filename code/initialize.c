/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:15:27 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/04 13:02:33 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_new_to_back(int content, t_list **lst)
{
	t_list	*new;
	t_list	*p;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->content = content;
	new->next = NULL;
	p = ft_lstlast(*lst);
	if (p != NULL)
		p->next = new;
	else
		*lst = new;
}

void	free_input(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
}

int	free_stack(t_list **stack)
{
	t_list	*p;
	t_list	*q;

	p = *stack;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		if (q == NULL)
			return (1);
		free(q);
		q = NULL;
	}
	*stack = NULL;
	return (1);
}

int	make_string_stack(char *str, t_list **stack)
{
	char		**nums_str;
	int			i;
	long int	num;

	i = -1;
	if (check_str(str) == 1)
		return (1);
	nums_str = ft_split(str, ' ');
	while (nums_str[++i])
	{
		if (check_sign(nums_str[i]) == 1)
		{
			free_input(nums_str);
			return (free_stack(stack));
		}
		num = ft_atoi(nums_str[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_input(nums_str);
			return (free_stack(stack));
		}
		lstadd_new_to_back((int)num, stack);
	}
	free_input(nums_str);
	return (0);
}

int	make_stack(int argc, char **argv, t_list **stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_str(argv[i]) == 0)
		{
			if (make_string_stack(argv[i], stack) == 1)
			{
				free_stack(stack);
				return (1);
			}
		}
		else
		{
			if (stack)
				free_stack(stack);
			return (1);
		}
		++i;
	}
	return (0);
}
