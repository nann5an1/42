/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:08:33 by marvin            #+#    #+#             */
/*   Updated: 2024/08/27 19:08:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int i = 0;
    int end;
    int start;
    if(argc == 2)
    {
        while(argv[1][i]!= '\0')
                i++;
        while(i >= 0)
        {
            while(argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
                i--;
            end = i;
            while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
                i--;    
            start = i + 1;
            int flag = start;
            while(start <= end)
            {
                write(1, &argv[1][start], 1);
                start++;
            }
            if(flag != 0)
                write(1, " ", 1);
        }
    }
    write(1, "\n", 1);
}
