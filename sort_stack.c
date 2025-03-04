/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:39:44 by mgamraou          #+#    #+#             */
/*   Updated: 2025/03/04 15:54:25 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	if (!stack_a || !(*stack_a) || !stack_b)
		return ;
	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest);
	prep_for_push(stack_a, cheapest, 'a');
	prep_for_push(stack_b, cheapest->target, 'b');
	push_to_stack(stack_a, stack_b, 'b');
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target, 'a');
	push_to_stack(stack_b, stack_a, 'a');
}

void	min_to_top(t_stack **stack)
{
	while ((*stack)->number != (get_min(*stack)->number))
	{
		if (get_min(*stack)->above_median)
			rotate_stack(stack, 'a');
		else
			reverse_rotate_stack(stack, 'a');
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !stack_is_sorted(*stack_a))
		push_to_stack(stack_a, stack_b, 'b');
	if (len_a-- > 3 && !stack_is_sorted(*stack_a))
		push_to_stack(stack_a, stack_b, 'b');
	while (len_a-- > 3 && !stack_is_sorted(*stack_a))
	{
		initialize_a(*stack_a, *stack_b);
		push_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		initialize_b(*stack_a, *stack_b);
		push_to_a(stack_a, stack_b);
	}
	set_median_index(*stack_a);
	min_to_top(stack_a);
}
