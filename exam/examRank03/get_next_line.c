/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:55:07 by marvin            #+#    #+#             */
/*   Updated: 2024/10/29 21:55:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_str_dup(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    char *str_malloc = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (str[i])
    {
        str_malloc[i] = str[i];
        i++;
    }
    str_malloc[i] = '\0';
    return (str_malloc);
}

char	  *get_next_line(int fd)
{
    char line[70000];
    static char buffer[BUFFER_SIZE];
    static int buffer_pos;
    static int buffer_read;
    int i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if(buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_read <= 0)
                break;
        }
        if (line[i] == '\n')
            break;
        line[i] = buffer[buffer_pos++];
        i++;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_str_dup(line));
}

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
}