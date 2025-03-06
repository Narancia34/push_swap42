/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:34:42 by mgamraou          #+#    #+#             */
/*   Updated: 2025/03/04 15:53:33 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	check_input(ac, av);
	stack_a = create_stack(ac, av);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!stack_is_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			swap_stack(&stack_a, 'a');
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
