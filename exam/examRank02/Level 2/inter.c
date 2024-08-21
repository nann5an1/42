/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:26:56 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 18:26:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int main(int argc, char** argv)
{
    int i = 0;
    int j = 0;
    int len = 0;
    if(argc == 3)
    {
        while(argv[1][len] != '\0')
            len++;
        while(--len)
        {
            if(argv[1][i] == argv[1][len])
                
        }
        while(argv[1][i] != '\0')
        {
            j = 0;
            while(argv[2][j] != '\0')
            {
                if(argv[1][i] == argv[2][j])
                    write(1, &argv[1][i], 1);
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}