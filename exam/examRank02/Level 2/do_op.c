/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:09:15 by marvin            #+#    #+#             */
/*   Updated: 2024/08/19 22:09:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
int main(int argc, char** argv)
{
    int res;
    if(argc == 4)
    {
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);
    if(argv[2][0] == '*')
       printf("%d", atoi(argv[1]) * atoi(argv[3]));
    else if(argv[2][0] == '/')
        res = num1 / num2;
    else if(argv[2][0] == '+')
        res = num1 + num2;
    else if(argv[2][0] == '-')
        res = num1 - num2;
    else if(argv[2][0] == '%')
        res = num1 % num2;
    }
    printf("%d", res);
}