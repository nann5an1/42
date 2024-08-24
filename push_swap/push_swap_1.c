/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:50:58 by nsan              #+#    #+#             */
/*   Updated: 2024/08/24 13:39:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void display(t_struct_node* stack) 
{
    t_struct_node* Node = stack;
    while (Node != NULL) {
        printf("%d -> ", Node->data);
        Node = Node->next;
    }
    printf("NULL\n");
}

void show_lst(t_struct_node* stackA, t_struct_node* stackB) 
{
    t_struct_node* stackb = stackB;
    t_struct_node* stacka = stackA;
    while (stacka != NULL || stackb != NULL) {
        if (stacka != NULL)
        {
            printf("%d", stacka->data);
            stacka = stacka->next;
        }
        else
            printf("\t");
        if (stackb != NULL)
        {
            printf("%d\t", stacka->data);
            stackb = stackb->next;
        }
        else
            printf("\n");
    }
    printf("-\t-\n");
    printf("a\tb\n\n");
    // printf("NULL\n");
}

void push(struct node** headref, int new_data)
{
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*headref);
    *headref = new_node;
}

int main(int argc, char** argv) 
{
    struct node* stackA = NULL;
    struct node* stackB = NULL;
    /* The constructed linked list is: 
     1->2->3->4->5 */
    
    if (argc >= 5)
    {
        while(argc > 1)
        {
            int j = atoi(argv[argc-1]);
            push(&stackA, j);
            //do_op_more();
            argc--;
        }
    }
    else if(argc == 3 && argc ==4)
        do_op();
    else
        printf("Require at least 2 arguments");

    show_lst(stackA, stackB); 

    //int midpoint = getMid(start);
    //printf("%d\n", midpoint);
    //show_lst(start);
    //display(stackA);
    //printf("%d", getMid(stackA));
    check(stackA, stackB);
    //show_lst(stackA, stackB);
    
    // // printf("\nLinked list after removing last to front\n"); 
    // r_rotate(&stackA); 
    // show_lst(stackA, stackB); 

    // // rotate(&start);
    // // show_lst(start); 

    // // printf("\nLinked list after 2 digits swapping\n"); 
    // swap(&stackA);
    // show_lst(stackA, stackB); 
    return 0;
}