/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:05:31 by nsan              #+#    #+#             */
/*   Updated: 2024/10/27 20:41:16 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_point size, t_point cur)
{
	if (size.x < 0 || cur.x >= size.x || size.y < 0 || cur.y >= size.y || \
	tab[cur.y][cur.x] == 'E' || \
	(tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'P' \
	&& tab[cur.y][cur.x] != '0' && \
	tab[cur.y][cur.x] != 'E'))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill (tab, size, (t_point){cur.x - 1, cur.y});
	fill (tab, size, (t_point){cur.x + 1, cur.y});
	fill (tab, size, (t_point){cur.x, cur.y - 1});
	fill (tab, size, (t_point){cur.x, cur.y + 1});
}

int	flood_fill(char **tab, t_point size, t_point begin)
{
	int	i;
	int	j;

	i = -1;
	fill (tab, size, begin);
	while (++i < size.y)
	{
		j = -1;
		while (++j < size.x)
		{
			if (tab[i][j] == 'C' || (tab[i][j] == 'E' && \
			(tab[i - 1][j] != 'F' && tab[i + 1][j] != 'F' && \
			tab[i][j - 1] != 'F' && tab[i][j + 1] != 'F')))
			{
				strfd("Path is not validated with flood fill.\n", 2);
				return (1);
			}
		}
	}
	return (0);
}
