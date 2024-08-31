/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:29:01 by nsan              #+#    #+#             */
/*   Updated: 2024/08/14 15:32:21 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void show_lst(t_struct_node* stack) 
{
    t_struct_node* current = stack;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    t_struct_node* stack_a;
    // t_struct_node* stack_b = NULL;

    // //have to be modified back
    // // if (argc <= 2 || (argc <=2 && !argv[1]))
    // //      write(1, "Error!More than 2 arguments is required for swapping.", 60);

    t_struct_node* node = (t_struct_node*)malloc(sizeof(t_struct_node));
    if (node == NULL)
        printf("Memory allocation failed\n");
    stack_a->data = 10;
    stack_a->next = NULL; //the tail of the linked list
    show_lst(stack_a);
    
}


// void    show_lst(node* lst)
// {
//     while (lst)
//     {
//         printf("%d ", lst->data);
//         lst = lst->next;
//     }
//     printf("\n");
// }

// #include <stdio.h>

// // Define the structure for linked list nodes
// typedef struct lst {
//     int data;
//     struct lst* next;
// } node;

// // Function to print the linked list


// int main() {
//     // Create an array of nodes for the static linked list
//     node nodes[3];

//     // Initialize the nodes with data
//     nodes[0].data = 1;
//     nodes[1].data = 2;
//     nodes[2].data = 3;

//     // Link the nodes together
//     nodes[0].next = &nodes[1];
//     nodes[1].next = &nodes[2];
//     nodes[2].next = NULL; // The last node points to NULL

//     // Print the linked list
//     show_lst(nodes);

//     return 0;
// }

//arguments checking (will use string split if the arguemnt is string)
//error handling
//operations --> conditioning using the 3, 2 numbers
//creation of nodes
//functions for rules and functions for comparison operations

//tester --> ./push_swap 2 1 3 6 5 8
