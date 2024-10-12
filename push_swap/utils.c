/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:38:53 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 09:38:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int getLength(t_struct_node *head)
{
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return (length);
}

int is_sorted(t_struct_node *ref)
{
    int flag;
    t_struct_node *current;

    current = ref;
    while(current->next != NULL)
    {
        if (current->data > current->next->data)  //not sorted
            return (0);
        current = current->next;
    }
    return (1);
    printf("stack is already sorted");
}

int minVal(t_struct_node *ref)
{
    if(ref == NULL)
        return (0);
    t_struct_node* min_node = ref;
    while(ref)
    {
        if(ref->data < min_node->data)
            min_node = ref;
        ref = ref->next;
    }
    return (min_node->data);
}

int maxVal(t_struct_node *ref)
{
    if(ref == NULL)
        return (0);
    t_struct_node* max_node = ref;

    if (ref->next == NULL)
        return (max_node->data);
    while(ref)
    {
        if(ref->data > max_node->data)
            max_node = ref;
        ref = ref->next;
    }
    return (max_node->data);
}
t_struct_node	*ft_lstnew_struct(int data)
{
    t_struct_node *new;

    new = (t_struct_node *)malloc(sizeof(t_struct_node));
    if (!new)
		return (NULL);
    new->data = data;
    new->next = NULL;
    return (new);
}

void	ft_lstadd_back_struct(t_struct_node **lst, t_struct_node *new)
{
	ft_lstadd_back((t_list **)lst, (t_list *)new);
}

int    ft_lstsize_struct(t_struct_node *lst)
{
    ft_lstsize((t_list *)lst);
}

long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
t_struct_node *cloned(t_struct_node* head)
{
    if (head == NULL)
        return (NULL);
    t_struct_node *new_head = (t_struct_node*)malloc(sizeof(t_struct_node));
    new_head->data = head->data;
    new_head->next = cloned(head->next);
    return (new_head);
}

t_struct_node* sort_ascend(t_struct_node* head)
{
    int temp;
    t_struct_node* ref = head;
    t_struct_node* next_node;
    while(ref != NULL)
    {
        next_node = ref->next;
        while(next_node != NULL)
        {
            if(ref->data > next_node->data)
            {
                temp = ref->data;
                ref->data = next_node->data;
                next_node->data = temp;
            }
            next_node = next_node->next;
        }
        ref = ref->next;
    }
    // head = ref;
    return (head);
}

void    lst_to_array(int *array, t_struct_node *cloned_A, int lst_size)
{
    int i = -1;
    while (++i < lst_size)
    {
        array[i] = cloned_A->data;
        cloned_A = cloned_A->next;
    }
}

int    find_index_in_sorted(int *array, int value, int lst_size)
{
    int i;
    i = -1;
    while (++i < lst_size)
    {
        if (array[i] == value)
            return (i);
    }
    return (-1);
}

void    index_replace(t_struct_node **stackA)
{
    t_struct_node   *temp_stack;
    t_struct_node   *original_cloned_stackA;
    t_struct_node   *cloned_stackA;
    t_struct_node   *cloned_sorted;

    int lst_size = ft_lstsize_struct(*stackA);
    cloned_stackA = cloned(*stackA);
    cloned_sorted = sort_ascend(cloned_stackA);

    int *array = (int*)malloc(sizeof(int) * lst_size);
    lst_to_array(array, cloned_sorted, lst_size);
    temp_stack = *stackA;
    while (temp_stack)
    {
        int value = temp_stack->data;
        int index = find_index_in_sorted(array, value, lst_size);
        temp_stack->data = index;
        temp_stack = temp_stack->next;
    }
    free (array);
}

