/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:38:53 by mgamraou          #+#    #+#             */
/*   Updated: 2025/02/25 11:26:19 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_up(char *str, char **arr)
{
	int	i;

	if (str)
		free(str);
	if (arr)
	{
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

void	check_args(char *arg)
{
	char	**s_arg;
	int		i;
	int		j;

	if (!arg || !arg[0])
	{
		printf("test_error\n");
		exit(1);
	}
	s_arg = ft_split(arg, ' ');
	i = 0;
	while (s_arg[i])
	{
		j = 0;
		while (s_arg[i][j])
		{
			if (s_arg[i][j] == '+' || s_arg[i][j] == '-')
				if (j == 0)
					j++;
			if (s_arg[i][j] < '0' || s_arg[i][j] > '9')
			{
				ft_putstr_fd("error\n", 2);
				clean_up(NULL, s_arg);
				exit(1);
			}
			j++;
		}
		i++;
	}
	clean_up(NULL, s_arg);
}

int	check_input(int ac, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		check_args(av[i]);
		i++;
	}
	return (0);
}
