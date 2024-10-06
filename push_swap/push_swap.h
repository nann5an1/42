/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:40:35 by nsan              #+#    #+#             */
/*   Updated: 2024/10/06 23:17:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//define the structure of the node of the linked list
// typedef struct node{
//     int data;
//     int index;
//     int push_count;
//     int target_node;
//     struct node* next; //will form a link to the rest of the nodes
// } t_struct_node;

typedef struct node{
    int index;
    int data;
    struct node* next;
}t_struct_node;

void swap(t_struct_node** headRef);
void r_rotate(t_struct_node** headref);
void rotate(struct node** headref);
void check(t_struct_node* stackA, t_struct_node* stackB);
void add_list(struct node** headref, int new_data);
int getLength(struct node* head);
void do_op(t_struct_node *stackA);
void push(t_struct_node **dest, t_struct_node **src);
void show_lst(t_struct_node *stack);
// t_struct_node* sort_ascend(t_struct_node* head);
// t_struct_node *cloned(t_struct_node* head);
// t_struct_node *maxNode(t_struct_node *ref);
// t_struct_node *do_sort(t_struct_node **head);
t_struct_node	*ft_lstnew_struct(int data);
void	ft_lstadd_back_struct(t_struct_node **lst, t_struct_node *new);
void sort_three(t_struct_node **stack);
void init_stack(t_struct_node **stackA, int count, char *argv[]);
int maxNode(t_struct_node *ref);
int minNode(t_struct_node *ref);
int is_sorted(t_struct_node* ref);
void    sort_four(t_struct_node **stackA);
void    sort_five(t_struct_node **stackA);

#endif
