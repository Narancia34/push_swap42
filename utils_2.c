/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:33:25 by mgamraou          #+#    #+#             */
/*   Updated: 2025/02/28 18:19:16 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	stack_is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack || !stack->next)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while ((*stack_b) != cheapest->target && (*stack_a) != cheapest)
		rr(stack_a, stack_b, 1);
	set_median_index(*stack_a);
	set_median_index(*stack_b);
}

void	reverse_rotate_both(t_stack **stack_a, \
	t_stack **stack_b, t_stack *cheapest)
{
	while ((*stack_b) != cheapest->target && (*stack_a) != cheapest)
		rrr(stack_a, stack_b, 1);
	set_median_index(*stack_a);
	set_median_index(*stack_b);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_index)
{
	while ((*stack) != top_node)
	{
		if (top_node->above_median)
			rotate_stack(stack, stack_index);
		else
			reverse_rotate_stack(stack, stack_index);
	}
}
