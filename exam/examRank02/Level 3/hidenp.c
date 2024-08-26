/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 00:15:21 by marvin            #+#    #+#             */
/*   Updated: 2024/08/26 00:15:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int main(int argc, char** argv)
{
    int i = 0;
    int j;
    int flag = 0;
    if(argc == 3)
    {
        while(argv[1][i] != '\0')
        {
            while(argv[2][j] != '\0')
            {
                if(argv[1][i] == argv[2][j])
                {
                    flag = 1;
                    j += 1;
                    break;
                }
                else
                    flag = 0;  
                j++;
            }
            i++;
        }
        if (flag == 0)
            write(1, "0", 1);
        else
            write(1, "1", 1);
    }
    write(1, "\n", 1);
}
    
