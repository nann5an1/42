/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:52:35 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:52:35 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int main()
{
	int fd = open("output.txt", O_CREAT | O_WRONLY, 0644);
	//file creating and opening
	char c = 'c';
	ft_putchar_fd(c, fd);
	close(fd);
	return (0);
} */
