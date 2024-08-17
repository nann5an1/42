/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:40:35 by nsan              #+#    #+#             */
/*   Updated: 2024/08/16 19:24:54 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
    int data;
    struct node* next;
}t_struct_node;

void swap(t_struct_node** headRef);
void r_rotate(t_struct_node** headref);
void rotate(struct node** headref);
int getMid(struct node* head);
void check(t_struct_node* stackA, t_struct_node* stackB);
//void check(t_struct_node** stackA, t_struct_node** stackB);
void push(struct node** headref, int new_data);
void show_lst(t_struct_node* stackA, t_struct_node* stackB);
void display(t_struct_node* stack);
int getLength(struct node* head);

#endif
