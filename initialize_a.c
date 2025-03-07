/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:57:58 by mgamraou          #+#    #+#             */
/*   Updated: 2025/02/28 16:29:25 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_targets_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (stack_a)
	{
		best_match = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (stack_a->number > current_b->number \
			&& current_b->number > best_match)
			{
				best_match = current_b->number;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			target = get_max(stack_b);
		stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	set_cost_a(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->cost = len_a - (stack_a->index);
		if (stack_a->target->above_median)
			stack_a->cost += stack_a->target->index;
		else
			stack_a->cost += len_b - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	long	cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = 1;
}

void	initialize_a(t_stack *stack_a, t_stack *stack_b)
{
	set_median_index(stack_a);
	set_median_index(stack_b);
	set_targets_a(stack_a, stack_b);
	set_cost_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
