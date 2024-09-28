/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:52:30 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:52:32 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*sr;
	size_t	i;

	sr = (char *)str;
	i = 0;
	while (i < n)
	{
		sr[i] = c;
		i++;
	}
	return (str);
}

/* int main()
{
   //strcpy(str,"This is string.h library function");
   //puts(str);
	char str[] = "This is a string";
	memset(str, '$',7);
	puts(str);

	char str1[] = "This is a string";
	ft_memset(str1,'$',7);
	puts(str1);

   return(0);
} */