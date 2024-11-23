/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:21:52 by nsan              #+#    #+#             */
/*   Updated: 2024/10/27 21:42:23 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(t_map *g_map)
{
	if (g_map->player_count != 1)
		return (strfd("Error! There has to be 1 player.\n", 2), 1);
	if (!(g_map->collect_count > 0))
		return (strfd("Error! Collectible is less than 1.\n", 2), 1);
	if (g_map->exit_count != 1)
		return (strfd ("Error! There must be 1 Exit.\n", 2), 1);
	if (g_map->outsider >= 1)
		return (strfd ("Error! Unrelated character in the game map\n", 2), 1);
	return (0);
}

int	row_col(int bytes_read, char *buffer, t_map *g_map)
{
	int	i;
	int	row;
	int	col;

	row = 0;
	col = 0;
	i = -1;
	while (++i < bytes_read)
	{
		if (buffer[i] == '\n')
			row++;
	}
	i = -1;
	while (buffer[++i] != '\n' && buffer[i] != '\0')
		col++;
	row++;
	if (row <= 2 || col <= 2)
	{
		strfd ("The map must have at least 3 rows/columns.\n", 2);
		return (1);
	}
	g_map->width = col;
	g_map->height = row;
	return (0);
}

int	border_check(t_map *game_map)
{
	int	i;

	i = -1;
	while (++i < game_map->width)
	{
		if (game_map->map_array[0][i] != '1' || \
		game_map->map_array[game_map->height - 1][i] != '1')
			return (strfd("The game map is not a full proper border\n", 2), 1);
	}
	i = 0;
	while (++i < game_map->height - 1)
	{
		if (game_map->map_array[i][0] != '1' || \
		game_map->map_array[i][game_map->width - 1] != '1')
			return (strfd("The game map is not a full proper border\n", 2), 1);
	}
	return (0);
}

int	is_rectangular(t_map *game_map)
{
	int	i;
	int	row_len;
	int	expected_width;

	i = 0;
	if (game_map->map_array[i] == NULL)
	{
		strfd("Invalid map row\n", 2);
		return (1);
	}
	expected_width = ft_strlen ((const char *)game_map->map_array[i]);
	while (++i < game_map->height)
	{
		row_len = ft_strlen (game_map->map_array[i]);
		if (row_len != expected_width)
		{
			strfd ("Map is not a rectangle.\n", 2);
			return (1);
		}
	}
	return (0);
}

void	map_array_alloc(t_map *game_map)
{
	int	j;

	j = -1;
	game_map->map_array = malloc(sizeof(char *) * game_map->height);
	while (++j < game_map->height)
	{
		game_map->map_array[j] = malloc(sizeof(char) * (game_map->width + 1));
		ft_memset(game_map->map_array[j], 0, game_map->width + 1);
	}
	game_map->collect_count = 0;
	game_map->exit_count = 0;
	game_map->player_count = 0;
	game_map->outsider = 0;
}
