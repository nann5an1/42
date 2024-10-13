/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:24:36 by marvin            #+#    #+#             */
/*   Updated: 2024/10/03 13:24:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_struct_node *head)
{
	t_struct_node	*current;
	t_struct_node	*runner;

	current = head;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->data == runner->data)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_valid_int(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (isalpha(*str))
			return (0);
		str++;
	}
	return (1);
}

void	free_stack(t_struct_node *stack)
{
	t_struct_node	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free (temp);
	}
}

int	init_stack(t_struct_node **stackA, int count, char *argv[])
{
	int				i;
	t_struct_node	*new;

	i = 1;
	while (i <= count)
	{
		if (is_valid_int(argv[i]) == 0 || ft_atol(argv[i]) < -2147483648 \
		|| ft_atol(argv[i]) > 2147483647)
		{
			ft_putstr_fd ("Error\n", 2);
			free_stack (*stackA);
			return (1);
		}
		new = ft_lstnew_struct (ft_atoi (argv[i]));
		ft_lstadd_back_struct (stackA, new);
		i++;
	}
	if (check_duplicates (*stackA) == 1)
	{
		ft_putstr_fd ("Error\n", 2);
		free_stack (*stackA);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct_node	*stack_a;
	t_struct_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || argv[1] == "")
		return (1);
	if (init_stack (&stack_a, argc - 1, argv) == 1)
		return (1);
	if (is_sorted (stack_a) == 1)
	{
		free_stack (stack_a);
		return (0);
	}
	if (argc - 1 <= 5)
		simple_sort (&stack_a, argc - 1);
	else if (argc -1 > 5)
	{
		index_replace (&stack_a);
		sort_radix (&stack_a);
	}
	free_stack (stack_a);
	free_stack (stack_b);
	return (0);
}
