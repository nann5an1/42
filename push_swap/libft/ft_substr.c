/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:54:25 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:54:28 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	str = (char *)s;
	if (str == NULL)
		return (NULL);
	if (len >= ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	if (start >= ft_strlen(str))
		len = 0;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = start;
	while (j < start + len)
		dest[i++] = str[j++];
	dest[i] = '\0';
	return (dest);
}

/*  int main()
{
	char *s = "malloc protection !";
	printf("%s", ft_substr(s, 13, 5));
} */
