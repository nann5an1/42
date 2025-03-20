/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:48:02 by marvin            #+#    #+#             */
/*   Updated: 2024/12/22 12:48:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_echo(t_tokens **whole_list)
{
    bool new_line;
    new_line = true;
    int i;
    i = 1;
    if(ft_strncmp(whole_list[i]->str, "-n", 2) == 0)
    {
        new_line = false;
        i++;
        printf("it's -n\n");
    }
    else if(ft_strncmp(whole_list[i]->str, "-n", 2))
    {
        printf("not -n\n");
    }
    // while(whole_list[i])
    // {
    //     printf("%s", whole_list[i]->str);
    //     i++;
    // }
    // if(new_line)
    // {
    //     printf("\n");
    // }
}