/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:43:22 by marvin            #+#    #+#             */
/*   Updated: 2024/08/17 12:43:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int main(int argc, char** argv)
{
    int count;
    if(argc == 2)
    {
        int i = 0;
        while(argv[1][i])
        {
            if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
                count = argv[1][i] - 'a' + 1;
            else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                count = argv[1][i] - 'A' + 1;
            else
                count = 1;

            while(count--)
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}