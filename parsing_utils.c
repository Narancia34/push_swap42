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

long	ft_atol(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
			break ;
		i++;
	}
	return (res * sign);
}
