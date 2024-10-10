/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:40:35 by nsan              #+#    #+#             */
/*   Updated: 2024/10/08 13:43:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
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
    int data;
    struct node* next;
}t_struct_node;

typedef struct temp
{
    int i;
    int k;
}t_temp;

void swap(t_struct_node** headRef, char *str);
void r_rotate(t_struct_node** headref, char *str);
void rotate(struct node** headref, char *str);
void check(t_struct_node* stackA, t_struct_node* stackB);
void add_list(struct node** headref, int new_data);
int getLength(struct node* head);
void do_op(t_struct_node *stackA);
void push(t_struct_node **dest, t_struct_node **src, char *str);
void show_lst(t_struct_node *stack);
// t_struct_node* sort_ascend(t_struct_node* head);
// t_struct_node *cloned(t_struct_node* head);
// t_struct_node *maxNode(t_struct_node *ref);
// t_struct_node *do_sort(t_struct_node **head);
// void radix(t_struct_node **stackA, t_struct_node **stackB);
int maxVal(t_struct_node *ref);
int minVal(t_struct_node *ref);
t_struct_node	*ft_lstnew_struct(int data);
void	ft_lstadd_back_struct(t_struct_node **lst, t_struct_node *new);
void sort_three(t_struct_node **stack);
int init_stack(t_struct_node **stackA, int count, char *argv[]);
int maxNode(t_struct_node *ref);
int minNode(t_struct_node *ref);
int is_sorted(t_struct_node* ref);
void    sort_four(t_struct_node **stackA);
void    sort_five(t_struct_node **stackA);
void    simple_sort(t_struct_node **stackA, int node_count);
int findPosition(t_struct_node *stack, int value);
// void    sort_radix(t_struct_node **stackA);
void radix(t_struct_node **stackA, t_struct_node **stackB, t_temp *temp, int len);
// void radix_sort(t_struct_node **stackA, t_struct_node **stackB);
// void radix_sort(t_struct_node **stack_a, t_struct_node **stack_b);
int    ft_lstsize_struct(t_struct_node *lst);
long	ft_atol(const char *str);
t_struct_node    **handle_neg(t_struct_node **stackA);
void    main_radix(t_struct_node **stackA);
void    rr(t_struct_node **stackA, t_struct_node **stackB);
int max_bits(t_struct_node **stackA);


#endif
