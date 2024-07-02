/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:54:19 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:54:19 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*sr;
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	sr = (char *)s1;
	end = (int)ft_strlen(sr) - 1;
	while (sr[start] && ft_strrchr(set, sr[start]))
		start++;
	while (end > start && ft_strrchr(set, sr[end]))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = sr[start++];
	str[i] = '\0';
	return (str);
}

/* int main()
{
	char *s1 = "";
	char *s2 = "";
	//printf("%zu", i - 1);
	char *ret = ft_strtrim(s1, " \n\t");
} */