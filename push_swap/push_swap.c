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

int check_duplicates(t_struct_node *head) {
    t_struct_node *current = head;
    t_struct_node *runner;

    while (current != NULL) {
        runner = current->next;
        while (runner != NULL) {
            if (current->data == runner->data) {
                return (1);
            }
            runner = runner->next;
        }
        current = current->next;
    }
    return 0;
}

int is_valid_int(const char *str) {
    if (*str == '-' || *str == '+')
        str++;
    if (*str == '\0')
        return (0);   
    while (*str)
    {
        if (isalpha(*str) == 1024) //the input is alpha
            return (0);
        str++;
    }
    return (1);
}

int   init_stack(t_struct_node **stackA, int count, char *argv[])
{
    int i;
     t_struct_node *new;

    i = 1;
    while(i <= count)
    {
        if (is_valid_int(argv[i]) == 0 || atol(argv[i]) < -2147483648 || atol(argv[i]) > 2147483647)
        {
            ft_putstr_fd("Error\n", 2);
            return (1);
        }
        new = ft_lstnew_struct(ft_atoi(argv[i]));
        ft_lstadd_back_struct(stackA, new);
        i++;
    }
    if (check_duplicates(*stackA) == 1)
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    return (0);
}
int main(int argc, char **argv) 
{
    t_struct_node *stackA;
    int count;
    int sorted;
    
    stackA = NULL;
    if (argc == 1)
        return (1);
    if (init_stack(&stackA, argc - 1, argv) == 1)
        return (1);
    if (is_sorted(stackA) == 1)
        return (0);
    if (argc - 1 <= 5)
        simple_sort(&stackA, argc - 1);
    else if(argc -1 > 5)
        sort_radix(&stackA);
    return (0);
}


//arguemnet validation check (if argc <= 2 --> error)
//get number of argv(count of numbers) --> can add the arguments into the list and get the counts in it
//is_sorted()
//if not  sorted --> sort 3 --> sort 4 --> sort 5 --> accoridng to the counts
//else more than 5 do the radix sort



 //t_struct_node* stackB = NULL;
    /* The constructed linked list is: 
     1->2->3->4->5 */
    // while(--argc)
    //     add_list(&stackA, atoi(argv[argc]));
    // t_struct_node* node = sort_ascend(stackA);
    // int res = getMed(stackA);
    // printf("Median: %d", res);
    // printf("Before sorting and median: ");
    // show_lst(stackA, stackB);
    // do_op(stackA);