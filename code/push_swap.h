/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:49:19 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/04 12:10:47 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "limits.h"
#include "stdio.h"
#include <unistd.h>

//INITIALIZE
void	print_stack(t_list *stack);
int		make_stack(int argc, char **argv, t_list **stack);
void	lstadd_new_to_back(int content, t_list **lst);
void	free_input(char **str);
int		free_stack(t_list **stack);
int		make_string_stack(char *str, t_list **stack);

//CHECK
int		check_repeat(t_list *stack);
int		check_str(char *str);
int		check_sign(char *c);

//OPS
void	swap( t_list **stack, char name);
void	swap_a_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack, char name);
void	rotate_a_b(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack, char name);
void	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);

//ORDER
int		check_order(t_list **stack);
void	order(t_list **stack_a, t_list **stack_b);
void	order_algorithm(t_list **stack_a, t_list **stack_b);
void	order_three(t_list **stack_a);

//ALGORITHM
int		find_cheapest(t_list *stack_a, t_list *stack_b);
int		stack_size(t_list *stack);
void	make_move(t_list **stack_a, t_list **stack_b, int index);
int		val_to_insert(int num, t_list *stack, int size);
int		get_index_value(int index, t_list *stack);
int		val_set_b(t_list *stack_b, int index);
int		final_val(int val_b, int val_a);
void	best_move(int num, t_list *stack, int *minmax_val, int *minmax_num);