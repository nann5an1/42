/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:53:24 by nsan              #+#    #+#             */
/*   Updated: 2024/10/13 20:44:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char c)
{
	char	*dest;
	int		i;
	int		j;
	int		total_len;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	dest = malloc(sizeof(char) * (int)ft_strlen(s1) + 2);
	if (!dest)
		return (NULL);
	while (i < (int)ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = c;
	i++;
	dest[i] = '\0';
	return (dest);
}
