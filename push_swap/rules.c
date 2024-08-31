/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:31:51 by nsan              #+#    #+#             */
/*   Updated: 2024/08/30 22:06:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_struct_node** headRef) 
{    
    if(*headRef == NULL || (*headRef)-> next == NULL)
        return;    
        //Nodes to be swapped
    t_struct_node* first = *headRef;
    t_struct_node* second = (*headRef)->next;    //swapping nodes
    first->next = second->next;
    second->next = first;    *headRef = second;
}

void r_rotate(t_struct_node** headref)
{
    if(*headref == NULL || (*headref)-> next == NULL)
        return;
    
    //initializing the nodes first
    t_struct_node* secLast = NULL;
    t_struct_node* last = *headref; 

    //link the nodes 
    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;
    last->next = *headref;
    *headref = last;
}

void rotate(struct node** headref)
{
    if(headref == NULL || (*headref)->next == NULL)
        return;
    t_struct_node*  first;
    t_struct_node*  last;

    first = *headref;
    last = *headref;

    while(last->next != NULL)
        last = last->next;
    *headref = first->next;
    first->next = NULL;
    last->next = first;
}

void push(t_struct_node** dest, t_struct_node** src)
{
    t_struct_node* temp = *src;
    temp->next = NULL;
    if(*dest)
        temp->next = *dest;
    else
        temp->next = NULL;
    *dest = temp;
    *src = (*src)->next;
}

// int getMid(struct node* head) {
//     int length = getLength(head);
//     int mid_index = length/2;
//     while(mid_index--)
//         head = head->next;
//     return (head->data);
// }

// void check(t_struct_node* stackA, t_struct_node* stackB)
// {
//     // t_struct_node* stackB = NULL;
//     struct node* head = stackA;
//     t_struct_node* newstackA = NULL;
    
//     int mid = getMid(head);
//     //printf("%d", mid);
//     while(head != NULL)
//     {
//         if(head->data < mid)
//             push(&stackB, head->data);
//         else
//             push(&newstackA, head->data);
//         head = head->next;
//     }
//     //show_lst(newstackA, stackB);
//     display(newstackA);
//     display(stackB);
//     //return (stackB);
// }

// void check(t_struct_node** stackA, t_struct_node** stackB)
// {
//     t_struct_node* head = *stackA;
//     t_struct_node* newStackA = NULL;
//     t_struct_node* temp;

//     if (head == NULL)
//         return; // Handle empty stack case

//     int mid = getMid(head); // Calculate midpoint

//     // Traverse and separate elements
//     while (head != NULL)
//     {
//         temp = head; // Store current node
//         head = head->next; // Move to the next node

//         if (temp->data < mid)
//         {
//             // Push to stackB
//             temp->next = *stackB; // Update the next pointer of the current node to point to the existing stackB
//             *stackB = temp; // Update stackB to point to the current node
//         }
//         else
//         {
//             // Push to newStackA
//             temp->next = newStackA; // Update the next pointer of the current node to point to the existing newStackA
//             newStackA = temp; // Update newStackA to point to the current node
//         }
//     }

//     // Update stackA to point to newStackA
//     *stackA = newStackA;

//     // Display both stacks
//     show_lst(*stackA, *stackB);
// }

