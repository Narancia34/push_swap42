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

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (0);  // Not equal
        i++;
    }
    // Both strings must end at the same position to be equal
    if (s1[i] == '\0' && s2[i] == '\0')
        return (1);  // Equal
    else
        return (0);  // Not equal
}

void	false_command(char *command, t_stack **a, t_stack **b)
{
	free(command);
	free_stack(a);
	free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	apply_command(char *command, t_stack **a, t_stack **b)
{
	if (ft_strcmp("sa\n", command))
		swap_stack(a, 'x');
	else if (ft_strcmp("sb\n", command))
		swap_stack(b, 'x');
	else if (ft_strcmp("ss\n", command))
		ss(a, b);
	else if (ft_strcmp("pa\n", command))
		push_to_stack(b, a, 'x');
	else if (ft_strcmp("pb\n", command))
		push_to_stack(a, b, 'x');
	else if (ft_strcmp("ra\n", command))
		rotate_stack(a, 'x');
	else if (ft_strcmp("rb\n", command))
		rotate_stack(b, 'x');
	else if (ft_strcmp("rr\n", command))
		rr(a, b);
	else if (ft_strcmp("rra\n", command))
		reverse_rotate_stack(a, 'x');
	else if (ft_strcmp("rrb\n", command))
		reverse_rotate_stack(b, 'x');
	else if (ft_strcmp("rrr\n", command))
		rrr(a, b);
	else
		false_command(command, a, b);
}

void	handle_input(t_stack **a, t_stack **b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		apply_command(command, a, b);
		free(command);
		command = get_next_line(0);
	}
	free(command);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b = NULL;

	check_input(ac, av);
	stack_a = create_stack(ac, av);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	handle_input(&stack_a, &stack_b);
	if (stack_b || !(stack_is_sorted(stack_a)))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		ft_putstr_fd("ko\n", 1);
	}
	else
{
		free_stack(&stack_a);
		free_stack(&stack_b);
		ft_putstr_fd("ok\n", 1);
	}
	return (0);
}
