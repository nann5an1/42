/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:50:58 by nsan              #+#    #+#             */
/*   Updated: 2024/09/02 00:34:01 by marvin           ###   ########.fr       */
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

t_struct_node* sort_ascend(t_struct_node* head)
{
    int temp;
    t_struct_node* ref = head;
    while(ref->next != NULL)
    {
        if(ref->data > ref->next->data)
        {
            temp = ref->data;
            ref->data = ref->next->data;
            ref->next->data = temp;
        }
        ref = ref->next;
    }
    // head = ref;
    return (head);
}

int getMed(t_struct_node *head) //
{
    int i = 0;
    int num = 0;
    int med;
    //t_struct_node *ref = head;
    t_struct_node* sorted = sort_ascend(head);
    int node_count = getLength(head);
    if(node_count % 2 == 0)
    {
        while(i != ((node_count/2) - 1))
        {
            sorted = sorted->next;
            i++;
        }
        num += sorted->data;
        sorted = sorted->next;
        num +=sorted->data;
        //printf("%d", num);
        med = num/2;
    }
    else
    {
        while(i != node_count/2)
        {
            sorted = sorted->next;
            i++;
        }
        med = sorted->data;
    }
    return (med);
}
void push(t_struct_node** dest, t_struct_node** src) {
    if (*src == NULL)
        return; // No node to push
    
    t_struct_node* temp = *src;
    *src = (*src)->next; // Update src to point to the next node
    temp->next = *dest;  // Insert the node at the beginning of dest
    *dest = temp;        // Update dest to point to the new head
}
void show_lst(t_struct_node* stacka, t_struct_node* stackb) 
{
    t_struct_node* original_stackA = stacka;
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
    t_struct_node* node = sort_ascend(original_stackA);
    while(node)
    {
        printf("%d   ", node->data);
        node = node->next;
    }
    printf("\n\n");
}
void do_op(t_struct_node *stackA) // t_struct_node points to the first head of the linked list
{
    // t_struct_node *ref = stackA; //(*stackA is the head ref to its stack pointer)
    // t_struct_node *stackB = NULL;

    // int med = getMed(stackA);
    // while(stackA)
    // {
    //     //ref = stackA;
    //     while(ref)
    //     {
    //         if(ref->data < med)
    //         {
    //             push(&stackB, &stackA);
    //             //break;
    //         }
    //         ref = ref->next;
    //     }
    //     //break;
    //     if (ref == NULL)
    //         break;
    // }
    
    // while(stackA)
    // {
    //     if(stackA->data <= med)
    //     {
    //         //printf("Pushing %d from A to B\n", stackA->data);
    //         push(&stackB, &stackA);
    //     }
    //     else
    //         stackA = stackA->next;
    // }
    // stackA = ref;
    // show_lst(stackA, stackB);

    t_struct_node *ref = stackA; //(*stackA is the head ref to its stack pointer)
    t_struct_node *stackB = NULL;

    int med = getMed(stackA);
    printf("%d", med);
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