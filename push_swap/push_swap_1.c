/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:50:58 by nsan              #+#    #+#             */
/*   Updated: 2024/08/30 22:15:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void display(t_struct_node* stack) 
// {
//     t_struct_node* Node = stack;
//     while (Node != NULL) {
//         printf("%d -> ", Node->data);
//         Node = Node->next;
//     }
//     printf("NULL\n");
// }

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

int getMed(t_struct_node *head)
{
    t_struct_node *ref = head;
    int total = 0;
    while (head)
    {
        total += head->data;
        head = head->next;
    }
    head = ref;
    int node_count = getLength(head);
    int med = total / node_count;
    return (med);
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
void show_lst(t_struct_node* stacka, t_struct_node* stackb) 
{
    printf("\n\n");
    printf("Stack A\t\t");
    while (stacka != NULL)
    {
        printf("%d   ", stacka->data);
        stacka = stacka->next;
    }
    printf("\nStack B\t\t");
    while (stackb != NULL)
    {
        printf("%d   ", stackb->data);
        stackb = stackb->next;
    }
    printf("\n\n");
}
void do_op(t_struct_node *stackA) // t_struct_node points to the first head of the linked list
{
    t_struct_node *ref = stackA; //(*stackA is the head ref to its stack pointer)
    t_struct_node *stackB = NULL;

    int med = getMed(stackA);
    while(stackA)
    {
        if(stackA->data < med)
            push(&stackB, &stackA);
        stackA = stackA->next;
    }
    stackA = ref;
    show_lst(stackA, stackB);
}


void add_list(struct node** headref, int new_data)
{
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*headref);
    *headref = new_node;
}

int main(int argc, char** argv) 
{
    t_struct_node* stackA = NULL;
    //t_struct_node* stackB = NULL;
    /* The constructed linked list is: 
     1->2->3->4->5 */
    while(--argc)
        add_list(&stackA, atoi(argv[argc]));
    do_op(stackA);
    return 0;
}