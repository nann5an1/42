/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:36:23 by nsan              #+#    #+#             */
/*   Updated: 2024/10/17 15:48:36 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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

void	free_stack(t_struct_node **stack)
{
	t_struct_node	*temp;
	t_struct_node	*next;

	temp = *stack;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*stack = NULL;
}

void	handle_free(char **argv, int i, t_struct_node *stack_a)
{
	i = 0;
	while (argv[i])
	{
		free (argv[i]);
		i++;
	}
	free (argv);
	free_stack (&stack_a);
}
