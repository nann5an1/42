/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:12:03 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 13:12:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
unsigned char	swap_bits(unsigned char octet)
{
    return ((octet >> 4) | octet << 4);
}

// int main()
// {
//     unsigned char res = swap_bits('1');
//     int i = 8;
//     while(i--)
//         printf("%d", res >> i & 1);
// }