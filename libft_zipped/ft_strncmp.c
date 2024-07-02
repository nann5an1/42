/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:53:59 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:54:02 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sr1;
	unsigned char	*sr2;

	i = 0;
	sr1 = (unsigned char *)s1;
	sr2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (sr1[i] == sr2[i] && i < n - 1 && sr1[i])
		i++;
	return (sr1[i] - sr2[i]);
}

/*int	main(int argc, char *argv[])
{
	argc = 3;
	printf ("%d", ft_strncmp(argv[1], argv[2], 6));
	return (0);
}*/
