/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:58:57 by nsan              #+#    #+#             */
/*   Updated: 2024/10/17 15:58:57 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct node
{
	int			data;
	struct node	*next;
}	t_struct_node;

void			push(t_struct_node **dest, t_struct_node **src, char *str);
void			sort_three(t_struct_node **stack);
void			sort_four(t_struct_node **stackA);
void			sort_five(t_struct_node **stackA);
void			simple_sort(t_struct_node **stackA, int node_count);
void			swap(t_struct_node **headRef, char *str);
void			r_rotate(t_struct_node **headref, char *str);
void			rotate(struct node **headref, char *str);
void			sort_radix(t_struct_node **stackA);
int				val_max(t_struct_node *ref);
int				val_min(t_struct_node *ref);
int				is_sorted(t_struct_node *ref);
int				find_pos(t_struct_node *stack, int value);
int				ft_lstsize_struct(t_struct_node *lst);
long			ft_atol(const char *str);
int				max_bits(t_struct_node **stackA);
void			index_replace(t_struct_node **stackA);
void			free_stack(t_struct_node **stack);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
int				is_valid_int(const char *str);
int				check_duplicates(t_struct_node *head);
void			handle_free(char **argv, int i, t_struct_node *stack_a);
int				check_dup(char **argv);
void			init_stack(t_struct_node **stack_a, char **argv);
void			error_handle(char **argv, int i, \
t_struct_node *stack_a);
char			**input_validate(int argc, char **argv);
char			**new_argv(int argc, char **argv);
int				is_digit(char **argv);

#endif
