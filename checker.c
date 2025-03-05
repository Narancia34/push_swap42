/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:10:48 by mgamraou          #+#    #+#             */
/*   Updated: 2025/03/04 17:17:36 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_input(t_stack **a, t_stack **b)
{
	char	*command;

	command = get_next_line(0);
	printf("%s", command);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_input(ac, av);
	stack_a = create_stack(ac, av);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	handle_input(&stack_a, &stack_b);
}
