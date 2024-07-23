/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:15:22 by marvin            #+#    #+#             */
/*   Updated: 2024/07/03 16:15:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_remainder(int fd, char **remainder)
{
	int		readbyte;
	char	*temp_str;
	char	*buffer;

	readbyte = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(*remainder, '\n') && readbyte)
	{
		readbyte = read(fd, buffer, BUFFER_SIZE);
		if (readbyte >= 0)
		{
			buffer[readbyte] = '\0';
			temp_str = ft_strjoin(*remainder, buffer);
		}
		free(*remainder);
		if (readbyte < 0)
		{
			*remainder = NULL;
			return (free(buffer), 0);
		}
		*remainder = temp_str;
	}
	return (free(buffer), readbyte);
}

static char	*get_line(char **remainder)
{
	char	*newline_pos;
	int		init_len;
	char	*line;
	char	*temp_str;

	newline_pos = ft_strchr(*remainder, '\n');
	if (newline_pos)
		init_len = (newline_pos - *remainder) + 1;
	else
		init_len = ft_strlen(*remainder);
	line = malloc(sizeof(char) * (init_len + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *remainder, init_len + 1);
	if (newline_pos)
		temp_str = ft_strdup(newline_pos + 1);
	else
		temp_str = NULL;
	free(*remainder);
	*remainder = temp_str;
	return (line);
}

char	*get_next_line(int fd)
{
	int				readbyte;
	static char		*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		remainder = NULL;
		return (NULL);
	}
	readbyte = 1;
	if (!remainder)
		remainder = NULL;
	readbyte = read_remainder(fd, &remainder);
	if (!remainder)
		return (NULL);
	if (readbyte == 0 && (!remainder || *remainder == '\0'))
	{
		if (remainder)
			free(remainder);
		remainder = NULL;
		return (NULL);
	}
	return (get_line(&remainder));
}

// int main()
// {
//     int fd;
//     char *line;

//     fd = open("file.txt", O_RDONLY);
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line); // Free each line after processing
//     }
//     close(fd);
//     return 0;
// }