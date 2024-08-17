/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_land_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:24:04 by marvin            #+#    #+#             */
/*   Updated: 2024/08/17 14:24:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char** argv)
{
    if(argc == 4)
    {
        if(!argv[2][1] && !argv[3][1]) //checking if the arguments are one character only
        {
            int i = 0;
            while(argv[1][i])
            {
                if(argv[1][i] == argv[2][0])
                    argv[1][i] = argv[3][0];
                write(1, &argv[1][i], 1);
                i++;
            }
        }
        write(1, "\n", 1);
    }
}
