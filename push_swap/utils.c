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

// int minNode(t_struct_node *ref)
// {
//     int index;
//     int min_index;
//     int min_value;

//     min_value = INT_MAX;
//     index = 0;
//     min_index = 0;
//     if(ref == NULL)
//         return (0);
//     while(ref)
//     {
//         if(ref->data < min_value)
//         {
//             min_value = ref->data;
//             min_index = index;
//         }
//         index++;
//         ref = ref->next;
//     }
//     return (min_index);
// }

// int maxNode(t_struct_node *ref)
// {
//     int index;
//     int max_value;
//     int max_index;
    
//     index = 0;
//     max_index = 0;
//     max_value = INT_MIN;

//     if(ref == NULL)
//         return (0);
//     //t_struct_node* max_node = ref;
//     while(ref)
//     {
//         if(ref->data > max_value)
//         {
//             max_value = ref->data;
//             max_index = index;
//         }
//         ref = ref->next;
//         index++;
//     }
//     return (max_index);
// }


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

void show_lst(t_struct_node *stack) 
{
    printf("Stack A\t\t\n");
    while(stack != NULL)
    {
        printf("%d\n", stack->data);
        stack = stack->next;
    }


    // printf("\n\n");
    // printf("Stack A\t\t");
    // while (stacka != NULL)
    // {
    //     printf("%d   ", stacka->data);
    //     stacka = stacka->next;
    // }
    // printf("\nStack B\t\t");
    // while (stackb != NULL)
    // {
    //     printf("%d   ", stackb->data);
    //     stackb = stackb->next;
    // }
    // printf("\n\n");
}

t_struct_node    **handle_neg(t_struct_node **stackA)
{
    t_struct_node *current;
    current = *stackA;
    if (minVal(*stackA) < 0)
    {
        while (current)
        {
            current->data += -(minVal(*stackA));
            current = current->next;
        }
    }
    // show_lst(*stackA);
    // sort_radix(stackA);
    return (stackA);
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
// int	main(void)
// {
// 	char	str[] = "++278520005";
// 	printf("%d\n", ft_atoi(str));
// 	char *s = "++278520005";
// 	int res = atoi(s);
// 	printf("%d\n", res);
// }

t_struct_node *cloned(t_struct_node* head)
{
    if (head == NULL)
        return (NULL);
    t_struct_node *new_head = (t_struct_node*)malloc(sizeof(t_struct_node));
    new_head->data = head->data;
    new_head->next = cloned(head->next);
    return (new_head);
}
void    convert_to_index(t_struct_node **stackA)
{
    t_struct_node   *temp_stack;
    t_struct_node   *original_cloned_stackA;

    int lst_size = ft_lstsize_struct(*stackA);
    t_struct_node *cloned_stackA = cloned(*stackA);
    original_cloned_stackA = cloned_stackA;
    //t_struct_node **stackA= (t_struct_node **)(sizeof(t_struct_node) * (lst_size + 1));
    //int max_node = maxNode(temp_stack);
    
    // show_lst(*stackA);
    while (lst_size - 1 >= 0)
    {
        temp_stack = *stackA;
        int max_val = maxVal(*stackA); //210
        while ((*stackA) && cloned_stackA)
        {
            if (cloned_stackA->data == max_val)
            {
                (*stackA)->data = lst_size - 1;
                break;
            }
            (*stackA) = (*stackA)->next;
            cloned_stackA = cloned_stackA->next;
        }
        lst_size--;
        *stackA = temp_stack;
        cloned_stackA = original_cloned_stackA;
    }
    // show_lst(*stackA);
}