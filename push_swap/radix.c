/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:24:26 by marvin            #+#    #+#             */
/*   Updated: 2024/10/08 11:24:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int max_bits(t_struct_node **stackA)
{
    int max;
    int max_bits;
    t_struct_node *ref;

    max_bits = 0;
    ref = *stackA;
    max = ref->data;
    while (ref != NULL)
    {
        if (ref->data > max)
            max = ref->data;
        ref = ref->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}
// ///////////////////////////////////////////////////
// void    sort_radix(t_struct_node **stack)
// {
//     t_struct_node   *ref;
//     t_struct_node   *stackB;
//     t_struct_node   **stackA;
//     int m_bits;
//     int bit_index;
//     int size;
//     int i;

//     i = 0;
//     stackB = NULL;
//     bit_index = 0;
//     stackA = handle_neg(stack);
//     size = ft_lstsize_struct(*stackA);
//     m_bits= max_bits(stackA);
//     while (bit_index < m_bits)
//     {
//         i = 0;
//         while (i < size)
//         {
//             ref = *stackA;
//             if (((ref->data >> bit_index) & 1 ) == 1)
//                 rotate(stackA, "ra\n");
//             else
//                 push(&stackB, stackA, "pb\n");
//             i++;
//         }
//         while (stackB != NULL)
//             push(stackA, &stackB, "pa\n");
//         bit_index++;
//     }
//     //show_lst(*stackA);
// }

///////////////////////////////////////////////////
void    sortB_radix(int size, int bit_index, int max_bits, t_struct_node **stackA, t_struct_node **stackB)
{
    // t_struct_node   *ref;
    // ref = *stackB;
    while (size > 0 && bit_index < max_bits && is_sorted(*stackA) == 0)
    {
        if (is_sorted(*stackA)) {
            return; // Stop further processing
        }
        if ((*stackB) != NULL && (*stackA) != NULL)
        {
            if ((*stackB) && (((*stackB)->data >> bit_index) & 1 == 0))
            {
                // if (((*stackA)->data >> bit_index) & 1 == 1)
                //     rr(stackA, stackB);
                // else
                    rotate(stackB, "rb\n");
            }
            else if (ft_lstsize_struct(*stackB) > 0)
                push(stackA, stackB, "pa\n");
        }
        size--;
    }
    // if (is_sorted(*stackA) == 1)
    // {
    //     while (ft_lstsize_struct(*stackB) > 0)
    //         push(stackA, stackB, "pa\n");
    // }
}

// void radix_sort(t_struct_node **stackA, t_struct_node **stackB) {
//     int j;
//     int bit_size = 0;
//     int size = ft_lstsize_struct(*stackA); // Assuming you have a function to get the size

//     // Determine the number of bits needed for the maximum value
//     while ((size >> bit_size) > 0) {
//         bit_size++;
//     }

//     // Iterate through each bit position
//     for (j = 0; j < bit_size; j++) {
//         size = ft_lstsize_struct(*stackA);
//         while (size-- && is_sorted(*stackA) != 0) { // Assuming you have an is_sorted function
//             if (((*stackA)->data >> j) & 1 == 0) {
//                 push(stackB, stackA, "pb\n"); // Push to stack B
//             } else {
//                 rotate(stackA, "ra\n"); // Rotate stack A
//             }
//         }
//         // Move elements back from stack B to stack A
//         while (*stackB != NULL) {
//             push(stackA, stackB, "pa\n"); // Move back to stack A
//         }
//         show_lst(*stackA);
//     }
// }

void    sort_radix(t_struct_node **stackA)
{
    t_struct_node   *ref;
    t_struct_node   *stackB;
    // t_struct_node   **stackA;
    int m_bits;
    int bit_index;
    int size;
    int i;

    i = -1;
    stackB = NULL;
    bit_index = 0;
    //stackA = handle_neg(stack);
    // is_less_than_10(stackA) //if less than 10 push to the hidden stack
    m_bits= max_bits(stackA);
    ref = *stackA;

    while (bit_index < m_bits)
    {
        i = -1;
        size = ft_lstsize_struct(*stackA);
        if (is_sorted(*stackA)) {
            break; // Stop further processing
        }
        while (++i < size)
        {
            ref = *stackA;
            if (((ref->data >> bit_index) & 1 ) == 0)
                push(&stackB, stackA, "pb\n");
            else
            {
                // if (ft_lstsize_struct(stackB) > 0 && ((stackB->data >> bit_index) & 1 == 0))
                //     rr(stackA, &stackB);
                // else
                    rotate(stackA, "ra\n");
            }
                
        }
        sortB_radix(ft_lstsize_struct(stackB), bit_index + 1, m_bits, stackA, &stackB); 
        while (ft_lstsize_struct(stackB) != 0)
            push(stackA, &stackB, "pa\n");
        bit_index++;
    }
    // show_lst(*stackA);
    // while (ft_lstsize_struct(stackB) != 0)
    //     push(stackA, &stackB, "pa\n");
    
    // show_lst(*stackA);
}


// void sort_radix(t_struct_node **stackA) {
//     t_struct_node *stackB = NULL;
//     int m_bits = max_bits(stackA);
    
//     for (int bit_index = 0; bit_index < m_bits; bit_index++) {
//         int size = ft_lstsize_struct(*stackA);
//         for (int i = 0; i < size; i++) {
//             if ((((*stackA)->data >> bit_index) & 1) == 1) {
//                 if (stackB && (((stackB->data >> bit_index) & 1) == 0)) {
//                     rr(stackA, &stackB); // Use rr for both stacks
//                 } else {
//                     rotate(stackA, "ra\n"); // Only rotate stackA
//                 }
//             } else {
//                 push(&stackB, stackA, "pb\n");
//             }
//         }

//         // Push all elements back from stackB to stackA
//         while (stackB != NULL) {
//             push(stackA, &stackB, "pa\n");
//         }
//     }
// }
///////////////////////////////////////////////////
// void    is_less_than_10(t_struct_node **stackA)
// {
//     t_struct_node   *ref;
//     t_struct_node   *stack;
//     ref = *stackA;

//     while (ref)
//     {
//         if (ref->data >= 0 && ref->data < 10)
//             stack->data = ref->data;
//         ref = ref->next;
//     }
// }

///////////////////////////////////////////////////
// void main_radix(t_struct_node **stackA)
// {
//     t_struct_node *ref;
//     t_struct_node *stackB;
//     t_struct_node *prev;

//     prev = NULL;
//     stackB = NULL;
//     ref = *stackA;

//     while (ref != NULL)
//     {
//         if (ref->data >= 100)
//         {
//             push(&stackB, stackA, "pb\n");

//             // Correctly update the previous pointer to skip the current node
//             if (prev != NULL)
//             {
//                 prev->next = ref->next;
//             }
//             else
//             {
//                 // If prev is NULL, we're removing the head of stackA
//                 *stackA = ref->next;
//             }

//             // Move ref to the next node
//             ref = (prev != NULL) ? prev->next : *stackA; // Move to the next node
//         }
//         else
//         {
//             // Move prev to current ref before rotating
//             prev = ref;
//             rotate(stackA, "ra\n");
//             ref = *stackA; // Reset ref to head of stackA
//         }
//     }

//     // show_lst(*stackA);
//     show_lst(stackB); // Uncomment this to show stackB contents.
// }

//////////////////////////////////////////////////////////////////////
// bool is_empty(t_struct_node *stack) {
//     return stack == NULL; // Stack is empty if the head is NULL
// }
// int count_digits(int num) {
//     int count = 0;
//     if (num == 0) return 1; // Handle zero case
//     while (num != 0) {
//         num /= 10;
//         count++;
//     }
//     return count;
// }

// // Main radix sort function
// void radix_sort(t_struct_node **stack_a, t_struct_node **stack_b) {
//     if (stack_a == NULL || *stack_a == NULL) return; // Check for null stack

//     int max_num = maxVal(*stack_a);
//     int max_digits = count_digits(max_num);
//     int size = ft_lstsize_struct(*stack_a); // Get size of stack_a

//     for (int digit = 0; digit < max_digits; digit++) {
//         for (int i = 0; i < size; i++) {
//             int current_digit = ((*stack_a)->data / (int)pow(10, digit)) % 10; // Get current digit

//             if (current_digit == 0) {
//                 push(stack_b, stack_a, "pb\n"); // Push to stack b
//             } else {
//                 rotate(stack_a, "ra\n"); // Rotate stack a
//             }
//         }

//         // Move numbers back from stack b to stack a
//         while (!is_empty(*stack_b)) {
//             push(stack_a, stack_b, "pa\n"); // Push from stack b back to stack a
//         }
//     }
// }

//////////////////////////////////////////////////////////////

// void radix_sort(t_struct_node **stackA, t_struct_node **stackB) {
//     int j;
//     int bit_size = 0;
//     int size = ft_lstsize(*stackA); // Assuming you have a function to get the size

//     // Determine the number of bits needed for the maximum value
//     while ((size >> bit_size) > 0) {
//         bit_size++;
//     }

//     // Iterate through each bit position
//     for (j = 0; j < bit_size; j++) {
//         size = ft_lstsize(*stackA);
//         while (size-- && !is_sorted(*stackA)) { // Assuming you have an is_sorted function
//             if ((((*stackA)->data >> j) & 1) == 0) {
//                 push(stackB, stackA); // Push to stack B
//             } else {
//                 rotate(stackA); // Rotate stack A
//             }
//         }
//         // Move elements back from stack B to stack A
//         while (*stackB != NULL) {
//             push(stackA, stackB); // Move back to stack A
//         }
//     }
// }
