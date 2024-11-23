/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:51:46 by nsan              #+#    #+#             */
/*   Updated: 2024/10/27 22:24:44 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ch_validate(int r, int c, t_map *g_map)
{
	if (g_map->map_array[r][c] == 'P')
		g_map->player_count++;
	else if (g_map->map_array[r][c] == 'C')
		g_map->collect_count++;
	else if (g_map->map_array[r][c] == 'E')
		g_map->exit_count++;
	else if (g_map->map_array[r][c] != '1' && g_map->map_array[r][c] != '0')
		g_map->outsider++;
}

int	m_validate(char **av, t_map *game_map)
{
	int	fd_ber;

	fd_ber = open(av[1], O_RDONLY);
	if (fd_ber < 0)
	{
		perror("Error reopening .ber file");
		exit(EXIT_FAILURE);
	}
	if (fill_map(fd_ber, game_map) == 1)
		return (1);
	if (is_rectangular(game_map) == 1)
		return (1);
	if (border_check(game_map) == 1)
		return (1);
	close(fd_ber);
	return (0);
}

int	file_validate(char **av)
{
	int	fd_ber;
	int	len;

	fd_ber = 0;
	len = ft_strlen (av[1]);
	if (len < 4 || ft_strncmp(av[1] + len - 4, ".ber", 4) == 0)
	{
		fd_ber = open(av[1], O_RDONLY);
		if (fd_ber < 0)
			return (strfd(".ber file path could not be opened", 2), -1);
		return (fd_ber);
	}
	else
	{
		ft_printf ("Extension must be .ber\n");
		return (-1);
	}
	return (fd_ber);
}
