/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:52:16 by mgamraou          #+#    #+#             */
/*   Updated: 2025/03/04 15:52:57 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	is_empty(char *arg)
{
	if (!arg || !arg[0] || is_only_spaces(arg))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	not_a_number(int i, int j, char **s_arg)
{
	if (s_arg[i][j] < '0' || s_arg[i][j] > '9')
	{
		ft_putstr_fd("error\n", 2);
		clean_up(NULL, s_arg);
		exit(1);
	}
}
