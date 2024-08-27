/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:08:37 by marvin            #+#    #+#             */
/*   Updated: 2024/08/27 12:08:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char** argv)
{
    int i;
    int k = 1;
    int count = argc - 1;
    if(argc > 1)
    {
        while(k <= count)
        {
            i = 0;
            while(argv[k][i] != '\0')
            {
                if(argv[k][i] == ' ' && argv[k][i+1] >= 'a' && argv[k][i+1] <= 'z') //get the first char of the word
                    argv[k][i+1] -= 32;
                else if(argv[k][0] >= 'a' && argv[k][0] <= 'z') //first char: (single char of the sentence)
                    argv[k][0] -= 32;
                else if(argv[k][i] >= 65 && argv[k][i] <= 122 && argv[k][i+1] >= 'A' && argv[k][i+1] <= 'Z') //the rest of the chars in the word
                    argv[k][i+1] += 32;
                write(1, &argv[k][i], 1);
                i++;
            }
            if(k < count)
                write(1, "\n", 1);
            k++;
        }
    }
    write(1, "\n", 1);
}