/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:51:16 by mgamraou          #+#    #+#             */
/*   Updated: 2025/02/28 16:49:46 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_stack	*last_node(t_stack *stack)*/
/*{*/
/*	t_stack	*res;*/
/**/
/*	if (!stack)*/
/*		return (NULL);*/
/*	res = stack;*/
/*	while (res->next)*/
/*		res = res->next;*/
/*	return (res);*/
/*}*/

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max_data;

	max_data = stack;
	while (stack)
	{
		if (stack->number > max_data->number)
			max_data = stack;
		stack = stack->next;
	}
	return (max_data);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->number < min->number)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	stack_len(t_stack *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void	set_median_index(t_stack *stack)
{
	int	index;
	int	median;

	index = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		index++;
	}
}
