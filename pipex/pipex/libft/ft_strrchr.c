/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:54:12 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 18:48:57 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)(s);
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((str + i));
		i--;
	}
	return (NULL);
}

/* int main()
{
	const char *str = "Hello world";
	int c = 'l';
	printf("%s\n", strrchr(str, c));
	printf("%s\n", ft_strrchr(str,c));
} */
