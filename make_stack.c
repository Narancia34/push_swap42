/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:56:21 by mgamraou          #+#    #+#             */
/*   Updated: 2025/02/25 14:11:59 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_stack *stack, int num)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->number == num)
			return (1);
		current = current->next;
	}
	return (0);
}

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = value;
	node->next = NULL;
	node->prev = NULL;
	node->target = NULL;
	node->cheapest = 0;
	return (node);
}

void	add_to_stack(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

t_stack	*handle_arg(char *arg, t_stack *stack)
{
	char	**numbers;
	int		i;
	long	num;
	t_stack	*new;

	numbers = ft_split(arg, ' ');
	i = 0;
	while (numbers[i])
	{
		num = atol(numbers[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			free_stack(&stack);
			return (clean_up(NULL, numbers), NULL);
		}
		if (has_duplicate(stack, (int)num))
		{
			free_stack(&stack);
			return (clean_up(NULL, numbers), NULL);
		}
		new = new_node((int)num);
		if (!new)
			return (clean_up(NULL, numbers), NULL);
		add_to_stack(&stack, new);
		i++;
	}
	clean_up(NULL, numbers);
	return (stack);
}

t_stack	*create_stack(int ac, char **av)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < ac)
	{
		stack = handle_arg(av[i], stack);
		if (!stack)
			return (NULL);
		i++;
	}
	return (stack);
}
