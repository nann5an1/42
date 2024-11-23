/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:16:30 by nsan              #+#    #+#             */
/*   Updated: 2024/10/17 18:46:40 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handle(char **argv, int i, t_struct_node *stack_a)
{
	strfd("Error\n", 2);
	handle_free(argv, i, stack_a);
	exit (1);
}

int	is_digit(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		i = 0;
		if ((*argv)[0] == '+' || (*argv)[0] == '-')
			i++;
		while ((*argv)[i])
		{
			if (ft_isdigit((*argv)[i]) == 0)
				return (1);
			i++;
		}
		argv++;
	}
	return (0);
}

char	**input_validate(int argc, char **argv)
{
	if (argc < 2 || !argv[1][0])
		exit (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
	{
		argv++;
		argv = new_argv(argc, argv);
	}
	return (argv);
}
