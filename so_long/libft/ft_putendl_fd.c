/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:52:41 by nsan              #+#    #+#             */
/*   Updated: 2024/10/02 16:10:48 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	strfd(s, fd);
	write(fd, "\n", 1);
}

/* int main()
{
	int fd = open("output.txt", O_CREAT | O_WRONLY, 0644);
	char *str = "Hello World";
	ft_putendl_fd(str, fd);
	close(fd);
	return (0);
} */