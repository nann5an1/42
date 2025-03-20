/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:45:47 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 11:45:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line_1.h"


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
    static char buffer[BUFFER_SIZE];
    static int buffer_pos;
    static int buffer_read;
    static char line[70000];
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

int main()
{
    int fd = open("test.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
}