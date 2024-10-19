/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:53:08 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:53:10 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(str + i));
	return (0);
}
// int main()
// {
//     const char *str = "Hello World";
//     char c = 'l';

//     char *res = strchr(str, c);
//     // printf("%p\n",(void *)res);
//     printf("%s\n",res);
//     printf(ft_strchr(str, c));
// }
