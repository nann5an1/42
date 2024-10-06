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


void   init_stack(t_struct_node **stackA, int count, char *argv[])
{
    int i;

    i = 1;
    t_struct_node *new;
    
    while(i <= count)
    {
        new = ft_lstnew_struct(ft_atoi(argv[i]));
        ft_lstadd_back_struct(stackA, new);
        i++;
    }
    // show_lst(*stackA);
    // sort_three(stackA);
    
}
int main(int argc, char **argv) 
{
    t_struct_node *stackA;
    int count;
    int sorted;
    
    stackA = NULL;

    count = argc - 1;
    if (argc == 1)
        ft_putstr_fd("Error\n", 2);
    init_stack(&stackA, count, argv);
    // if (is_sorted(stackA) == 0)
    //     sort_three(&stackA); //simple sort
    sort_five(&stackA);


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
    return 0;
}



//arguemnet validation check (if argc <= 2 --> error)
//get number of argv(count of numbers) --> can add the arguments into the list and get the counts in it
//is_sorted()
//if not  sorted --> sort 3 --> sort 4 --> sort 5 --> accoridng to the counts
//else more than 5 do the radix sort
