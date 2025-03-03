/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:04:41 by mgamraou          #+#    #+#             */
/*   Updated: 2025/03/01 12:07:38 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_targets_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_match;


	while (stack_b)
	{
		best_match = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->number > stack_b->number && current_a->number < best_match)
			{
				best_match = current_a->number;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			target = get_min(stack_a);
		stack_b->target = target;
		stack_b = stack_b->next;
	}
}

void	initialize_b(t_stack *stack_a, t_stack *stack_b)
{
	set_median_index(stack_a);
	set_median_index(stack_b);
	set_targets_b(stack_a, stack_b);
}
