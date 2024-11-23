/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:01:40 by nsan              #+#    #+#             */
/*   Updated: 2024/10/17 16:01:40 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct_node	*allocate_node(char **argv, int i)
{
	t_struct_node	*new_node;

	new_node = (t_struct_node *)malloc(sizeof(t_struct_node));
	if (!new_node)
	{
		handle_free(argv, i, NULL);
		exit (1);
	}
	new_node->data = ft_atoi(argv[i]);
	new_node->next = NULL;
	return (new_node);
}

void	init_stack(t_struct_node **stack_a, char **argv)
{
	int				i;
	t_struct_node	*new_node;
	t_struct_node	*temp;

	i = 0;
	*stack_a = NULL;
	while (argv[i])
	{
		if (is_valid_int(argv[i]) == 0 || \
		ft_atol(argv[i]) < -2147483648 || ft_atol(argv[i]) > 2147483647)
			error_handle(argv, i, *stack_a);
		new_node = allocate_node(argv, i);
		if (*stack_a == NULL)
			*stack_a = new_node;
		else
		{
			temp = *stack_a;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_node;
		}
		i++;
	}
	if (check_dup(argv) == 1)
		error_handle(argv, i, *stack_a);
}

char	**new_argv(int argc, char **argv)
{
	int		i;
	char	**new_av;

	i = 0;
	new_av = malloc(sizeof(char *) * argc);
	while (argv[i])
	{
		new_av[i] = ft_strdup(argv[i]);
		if (!new_av[i])
		{
			handle_free(new_av, i, NULL);
			return (NULL);
		}
		i++;
	}
	new_av[i] = NULL;
	return (new_av);
}

void	check_if_sorted(t_struct_node *stack_a)
{
	if (!is_sorted (stack_a))
	{
		if (ft_lstsize_struct(stack_a) <= 5)
			simple_sort (&stack_a, ft_lstsize_struct(stack_a));
		else
		{
			index_replace (&stack_a);
			sort_radix (&stack_a);
		}
	}
	free_stack(&stack_a);
}

int	main(int argc, char **argv)
{
	t_struct_node	*stack_a;
	t_struct_node	*stack_b;
	int				i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	argv = input_validate (argc, argv);
	if (is_digit (argv) == 1)
		error_handle (argv, i, stack_a);
	init_stack (&stack_a, argv);
	while (argv[i])
	{
		free (argv[i]);
		i++;
	}
	free (argv);
	check_if_sorted(stack_a);
	free_stack (&stack_b);
	return (0);
}
