/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:42:00 by mgamraou          #+#    #+#             */
/*   Updated: 2025/02/28 14:09:22 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack, char stack_index)
{
	int	tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->number;
	(*stack)->number = (*stack)->next->number;
	(*stack)->next->number = tmp;
	if (stack_index == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (stack_index == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int flag)
{
	swap_stack(stack_a, 's');
	swap_stack(stack_b, 's');
	if (flag == 1)
		ft_putstr_fd("ss\n", 1);
}

void	rotate_stack(t_stack **stack, char stack_index)
{
	t_stack	*first_block;
	t_stack	*last_block;

	if (!*stack || !(*stack)->next)
		return ;
	first_block = *stack;
	*stack = first_block->next;
	(*stack)->prev = NULL;
	last_block = last_node(*stack);
	last_block->next = first_block;
	first_block->prev = last_block;
	first_block->next = NULL;
	if (stack_index == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (stack_index == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rotate_stack(stack_a, 'r');
	rotate_stack(stack_b, 's');
	if (flag == 1)
		ft_putstr_fd("rr\n", 1);
}
