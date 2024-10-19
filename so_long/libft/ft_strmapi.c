/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:53:50 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:53:50 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char lower(unsigned int i, char c)
// {
//     (void)i;
//     if (c >= 65 && c <= 90)
// 		c += 32;
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*dest;
	int		len;
	int		j;

	j = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *)s;
	len = ft_strlen(str);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (j < len)
	{
		dest[j] = f(j, str[j]);
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

/* int main()
{
	char *str = "HeLLo World!";

	// Call ft_strmapi with the transformation function
	char *lowercase = ft_strmapi(str, lower);
	puts(lowercase);
} */