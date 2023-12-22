/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:15:15 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/05 11:51:51 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	input_manager(t_list **stack_a, t_list **stack_b)
{
	char	*movement;

	movement = get_next_line(0);
	if (movement == NULL)
		return (0);
	if (check_movement(movement, stack_a, stack_b) == 1)
	{
		write(1, "Error\n", 6);
		free_stack(stack_a);
		free_stack(stack_b);
		return (-1);
	}
	return (1);
}

void	check_result(t_list *stack_a, t_list *stack_b)
{
	if (check_order(&stack_a) == 0 && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	int		input;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	input = 1;
	if (argc < 2)
		return (1);
	if (make_stack(argc, argv, &stack_a) == 1)
	{
		if (stack_a == NULL)
			return (write(2, "Error\n", 6));
	}
	if (check_repeat(stack_a) != 0)
		return (write(2, "Error\n", 6));
	while (input == 1)
		input = input_manager(&stack_a, &stack_b);
	if (input == -1)
		return (1);
	check_result(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
