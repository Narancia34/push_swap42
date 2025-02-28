/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:42:37 by mgamraou          #+#    #+#             */
/*   Updated: 2025/02/28 15:02:41 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int	number;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
	int	index;
	int	above_median;
	int	cost;
	int	cheapest;
}   t_stack;

int	check_input(int ac, char **av);
void	clean_up(char *str, char **arr);
t_stack	*create_stack(int ac, char **av);
void	swap_stack(t_stack **stack, char stack_index);
t_stack	*last_node(t_stack *stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rotate_stack(t_stack **stack, char stack_index);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_stack(t_stack **stack, char stack_index);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	push_to_stack(t_stack **src_stack, t_stack **dst_stack, char stack_index);
void	free_stack(t_stack **stack);
int	stack_len(t_stack *stack);
t_stack	*get_min(t_stack *stack);
t_stack	*get_max(t_stack *stack);
void	sort_three(t_stack **stack);
void	set_median_index(t_stack *stack);

#endif
