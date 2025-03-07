/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:13:54 by mgamraou          #+#    #+#             */
/*   Updated: 2025/02/25 18:41:16 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack **stack, char stack_index)
{
	t_stack	*first_block;
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	first_block = *stack;
	*stack = last_node(*stack);
	before_last = (*stack)->prev;
	(*stack)->next = first_block;
	(*stack)->prev = NULL;
	first_block->prev = *stack;
	before_last->next = NULL;
	if (stack_index == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (stack_index == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	reverse_rotate_stack(stack_a, 'r');
	reverse_rotate_stack(stack_b, 'r');
	if (flag == 1)
		ft_putstr_fd("rrr\n", 1);
}

void	push_to_stack(t_stack **src_stack, \
	t_stack **dst_stack, char stack_index)
{
	t_stack	*first_block;

	if (!*src_stack)
		return ;
	first_block = *src_stack;
	*src_stack = (*src_stack)->next;
	if (*src_stack)
		(*src_stack)->prev = NULL;
	first_block->next = *dst_stack;
	first_block->prev = NULL;
	if (*dst_stack)
		(*dst_stack)->prev = first_block;
	*dst_stack = first_block;
	if (stack_index == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (stack_index == 'b')
		ft_putstr_fd("pb\n", 1);
}
