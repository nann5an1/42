/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:13:45 by marvin            #+#    #+#             */
/*   Updated: 2024/09/02 11:13:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
int getMed(t_struct_node *head) //
{
    int i = 0;
    int num = 0;
    int med;
   
    //t_struct_node *before_sort = head;
    //t_struct_node *temp_stack = NULL;  
    t_struct_node *sorted = sort_ascend(head);
    t_struct_node *temp = sorted;
    printf("Sorted out print in getMed:");
    while(temp)
    {
        printf("%d   ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");

    int node_count = getLength(sorted);
    printf("Node count: %d\n", node_count);

    if(node_count % 2 == 0)
    {
        while(i != ((node_count/2) - 1))
        {
            head = head->next;
            i++;
        }
        num += head->data;
        head = head->next;
        num +=head->data;
        //printf("%d", num);
        med = num/2;
    }
    else
    {
        while(i != node_count/2)
        {
            head = head->next;
            i++;
        }
        med = head->data;
    }
    return (med);
}
void add_list(struct node** headref, int new_data)
{
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*headref);
    *headref = new_node;
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
void push(t_struct_node** dest, t_struct_node* src)
{
    t_struct_node *temp = src;
    src = src->next;
    temp->next = *dest;
    *dest = temp;
}

// t_struct_node *cloned(t_struct_node* head)
// {
//     t_struct_node *new_head = (t_struct_node*)malloc(sizeof(t_struct_node));
//     new_head->data = head->data;
//     new_head->next = cloned(head->next);
//     return (new_head);
// }

void do_op(t_struct_node *stackA) // t_struct_node points to the first head of the linked list
{
    //t_struct_node *cloned_list = cloned(stackA);
    t_struct_node *ref = stackA; //(*stackA is the head ref to its stack pointer)
    //t_struct_node *temp = stackA;
    t_struct_node *stackB = NULL;
    t_struct_node  *prev = NULL;

    
    int med = getMed(stackA);
    printf("Median: %d\n", med);
    //show_lst(stackA,stackB);
    while(ref)
    {
        if(ref->data <= med)
        {
            t_struct_node *next_node = ref->next;
            if(prev)
                prev->next = ref->next;
            else
                stackA = ref->next;
            push(&stackB, ref);
            ref = next_node;
        }
        else
        {
            prev = ref;
            ref = ref->next;
        }
    }
    show_lst(stackA, stackB);
}
int main(int argc, char** argv) 
{
    t_struct_node* stackA = NULL;
    t_struct_node* stackB = NULL;
    /* The constructed linked list is: 
     1->2->3->4->5 */
    while(--argc)
        add_list(&stackA, atoi(argv[argc]));
    // t_struct_node* node = sort_ascend(stackA);
    // int res = getMed(stackA);
    // printf("Median: %d", res);
    printf("Before sorting and median: ");
    show_lst(stackA, stackB);
    do_op(stackA);
    return 0;
}