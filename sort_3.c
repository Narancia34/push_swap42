/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:54:52 by mgamraou          #+#    #+#             */
/*   Updated: 2025/02/28 14:23:35 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*highest_data;

	highest_data = get_max(*stack);
	if ((*stack) == highest_data)
		rotate_stack(stack, 'a');
	else if ((*stack)->next == highest_data)
		reverse_rotate_stack(stack, 'a');
	if ((*stack)->number > (*stack)->next->number)
		swap_stack(stack, 'a');
}
