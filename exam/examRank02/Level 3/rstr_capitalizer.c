/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:20:05 by marvin            #+#    #+#             */
/*   Updated: 2024/08/26 23:20:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int main(int argc, char** argv)
{
    int i = 0;
    int k = 1;
    int count = argc - 1;
    while (k <= count)
    {
        i = 0;
        while(argv[k][i] != '\0') //will go string by string
        {
            if(argv[k][i] >= 65 && argv[k][i] <= 90 && (argv[k][i+1] == ' ' || argv[k][i+1] == '\0')) //last character of the last word is uppercase
                argv[k][i]  = argv[k][i];
            else if(argv[k][i] >= 97 && argv[k][i] <= 122 && (argv[k][i+1] == ' ' || argv[k][i+1] == '\0'))//last character of the last word is lowercase
                argv[k][i] -= 32;
            else if(argv[k][i] >= 65 && argv[k][i] <= 90)//char: in between
                argv[k][i] += 32;
            write(1, &argv[k][i], 1);
            i++;
        }
        if (k < count)
            write(1, "\n", 1);
        k++;
    }
    write(1, "\n", 1);
}