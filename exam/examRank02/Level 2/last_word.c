/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:20:14 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 20:20:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int main(int argc, char** argv)
{
    int i = 0;
    int j = 0;
    if(argc == 2)
    {
        while(argv[1][i] != '\0')
        {
            if(argv[1][i] == ' ' && argv[1][i+1] >= 33 && argv[1][i+1] <= 126) //find the starting index of the word
                j = i + 1;
            i++;
        }
        while(argv[1][j] >= 33 && argv[1][j] <= 126)
        {
            write(1, &argv[1][j], 1);
            j++;
        }
    }
    write(1, "\n", 1);
}