/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:09:21 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 19:09:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	    is_power_of_2(unsigned int n)
{
    if(n == 0)
        return (0);    
    return ((n & (n-1)) == 0);
}

int main()
{
    printf("%d", is_power_of_2(25));
}