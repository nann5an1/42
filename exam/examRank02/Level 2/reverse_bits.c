/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:55:36 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 12:55:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
unsigned char	reverse_bits(unsigned char octet)
{
    int res = 0;
    int i = 8;
    while(i--)
    {
        res = res * 2 + (octet % 2); 
        octet = octet/2;
    }
    return (res);
}

int main()
{
    int i = 8;
    unsigned char res = reverse_bits('1');
    while(i--)
        printf("%d", res >> i & 1);
}
