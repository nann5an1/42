/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:46:11 by marvin            #+#    #+#             */
/*   Updated: 2024/08/27 22:46:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// int* sort_int_tab(int *tab, unsigned int size)
// {
//     int temp;
//     int i = 0;
//     while (i < (size - 1))
//     {
//         if(tab[i] > tab[i+1])
//         {
//             temp = tab[i];
//             tab[i] = tab[i+1];
//             tab[i+1] = temp;
//             i = 0; //is set to '0' to loop once again and check if tab[i] > tab[i+1]
//         }
//         else
//             i++;
//     }
//     return (tab);
// }
int *sort_int_tab(int *tab, unsigned int size)
{
    int temp;
    int i = 0;
    //int largest = tab[0];
    while(i < size - 1)
    {
        if(tab[i] > tab[i+1])
        {
           temp = tab[i];
           tab[i] = tab[i+1];
           tab[i+1] = temp;
           i = 0;
        }
        else
            i++;  
    }
}
int main()
{
    int i = 0;
    int tab[] = {6, 0, -4};
    int *res = sort_int_tab(tab, 3);
    while(i < 3)
    {
        printf("%d", tab[i]);   
        i++;
    }
}

