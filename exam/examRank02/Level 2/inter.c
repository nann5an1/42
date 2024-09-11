/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:15:09 by marvin            #+#    #+#             */
/*   Updated: 2024/09/08 22:15:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// int main(int argc, char** argv)
// {
//     int i = 0;
//     int j;
//     if(argc == 3)
//     {
//         unsigned char seen[256] = {0};
//         while(argv[1][i] != '\0')
//         {
//             j = 0;
//             while(argv[2][j])
//             {
//                 if(argv[1][i] == argv[2][j])
//                 {
//                     if(!seen[(unsigned char)argv[1][i]])
//                     {
//                         write(1, &argv[1][i], 1);
//                         seen[(unsigned char)argv[1][i]] = 1;
//                     }
//                     break;
//                 }
//                 j++;
//             }
//             i++;
//         }
//     }
//     write(1, "\n", 1);
// }


int main(int ac, char** av)
{
    int i = 0;
    int j;
    if(ac == 3)
    {
        unsigned char seen[256] = {0};
        while(av[1][i])
        {
            j = 0;
            while(av[2][j])
            {
                if(av[1][i] == av[2][j])
                {
                    if(!seen[(unsigned char)av[1][i]])
                    {
                        write(1, &av[1][i], 1);
                        seen[(unsigned char)av[1][i]] = 1;
                    }
                    break;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}


