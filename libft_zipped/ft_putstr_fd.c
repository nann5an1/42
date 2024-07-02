/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:52:52 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:52:54 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/* int main()
{
	int fd = open("output.txt", O_CREAT | O_WRONLY, 0644);
	//file creating and opening
	char *msg = "Hello world";
	ft_putstr_fd(msg, fd);
	close(fd);
	return (0);
} */