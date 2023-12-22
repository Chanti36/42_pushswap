/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:49 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/05 10:46:49 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "limits.h"
#include "stdio.h"
#include <unistd.h>
#define BUFFER_SIZE 4

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
int		check_order(t_list **stack);

//OPS
void	swap( t_list **stack);
void	swap_a_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	rotate_a_b(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack);
void	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);

int		check_movement(char *movement, t_list **stack_a, t_list **stack_b);

//GNL
int		ft_find_line(char *buff);
char	*ft_substr(char const *s, unsigned int str, size_t len);
size_t	ps_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ps_strjoin(char *s1, char const *s2);
char	*ft_get_line(char *buff);
char	*ft_resize_buff(char *buff);
char	*get_text(char *buff, int fd);
char	*result(char **buff, char *aux);
char	*get_next_line(int fd);
