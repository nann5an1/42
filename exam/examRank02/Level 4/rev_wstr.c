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

int main(int argc, char** argc)
{
    int i;
    int end;
    if(argc == 2)
    {
        while(argv[1][i]!= '\0')
            i++;
        while(argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == "\t")
            i--;
        end = i;
        while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != "\t")
            i--;    
    }
}
