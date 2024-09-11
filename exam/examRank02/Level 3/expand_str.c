/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:24:05 by marvin            #+#    #+#             */
/*   Updated: 2024/08/25 11:24:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int main(int argc, char** argv)
{
    int i = 0;
    int j = 0;
    if(argc == 2)
    {
        while(argv[1][i])
        {
            if(argv[1][i] >= 33 && argv[1][i] <= 126 && argv[1][i+1] != ' ')
                write(1, &argv[1][i], 1);
            else if(argv[1][i] >= 33 && argv[1][i] <= 126 && argv[1][i+1] == ' ')
            {
                j = 0;
                write(1, &argv[1][i], 1);
                while(j < 3)
                {
                    write(1, &argv[1][i+1], 1);
                    j++;
                }   
            }
            // else if(argv[1][i] == ' ' && (argv[1][i+1] == ' ' || (argv[1][i+1] >= 33 && argv[1][i] <= 126)))
            //     write(1, "", 1);
            i++;
        }
    }
    write(1, "\n", 1);
}