/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:15:33 by marvin            #+#    #+#             */
/*   Updated: 2024/08/17 13:15:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
char *rev_print(char *str)
{
    int i = 0;
    int len = 0;
    while(str[i])
        i++;

    while(i--)
        write(1, &str[i], 1);
    return (str);
}
int main(int argc, char** argv)
{
    char* str = "";
    rev_print(str);
}