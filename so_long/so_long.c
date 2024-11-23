/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:36:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/27 21:53:36 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_map_char(char buffer, int i, int j, t_map *game_map)
{
	game_map->map_array[i][j] = buffer;
	ch_validate (i, j, game_map);
}

int	fill_map(int fd, t_map *game_map)
{
	char	buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read(fd, &buffer, 1) > 0 && i < game_map->height)
	{
		if (buffer == '\n')
		{
			game_map->map_array[i++][j] = '\0';
			j = 0;
		}
		else if (j < game_map->width)
			process_map_char(buffer, i, j++, game_map);
		else
			return (strfd("The map is NOT a rectangle\n", 2), 1);
	}
	if (j > 0 && i < game_map->height)
		game_map->map_array[i][j] = '\0';
	if (error_msg(game_map) == 1)
		return (1);
	return (0);
}

void	begin_point(char **map, t_map *g_map, t_point *begin)
{
	int	i;
	int	j;

	j = 1;
	while (j <= g_map->height - 2)
	{
		i = 1;
		while (i <= g_map->width - 2)
		{
			if (map[j][i] == 'P')
			{
				begin->y = j;
				begin->x = i;
			}
			i++;
		}
		j++;
	}
}

int	game_struct(t_game *gmlx, char **av, int bytesRead, char *buffer)
{
	t_point	size;
	t_point	begin;
	t_map	*game_map;
	char	**game_cpy;

	game_map = (t_map *)malloc(sizeof(t_map));
	if (row_col(bytesRead, buffer, game_map) == 1)
		return (free_tmap(game_map));
	map_array_alloc (game_map);
	width_height_set (&size, gmlx, game_map);
	if (m_validate (av, game_map) == 1)
		return (free_game_map(game_map), 1);
	begin_point (game_map->map_array, game_map, &begin);
	game_cpy = (char **)malloc(sizeof(char *) * game_map->height);
	cpy_map (game_cpy, game_map);
	if (flood_fill (game_cpy, size, begin) == 1)
	{
		free_copy (game_cpy, game_map);
		return (free_game_map (game_map), 1);
	}
	gmlx->map_arr = (char **)malloc(sizeof(char *) * gmlx->height);
	cpy_map (gmlx->map_arr, game_map);
	free_copy (game_cpy, game_map);
	return (free_game_map (game_map), 0);
	return (0);
}

int	main(int ac, char **av)
{
	int		bytes_read;
	char	buffer[4096];
	t_game	gmlx;

	if (ac != 2)
		return (strfd("Wrong use of arguments", 2), 1);
	if (file_validate(av) == -1)
		return (1);
	else
	{
		bytes_read = read(file_validate(av), buffer, sizeof(buffer));
		buffer[bytes_read] = '\0';
		close(file_validate(av));
		if (game_struct(&gmlx, av, bytes_read, buffer) == 0)
		{
			win_init (&gmlx);
			find_player (&gmlx);
			render_map (&gmlx);
			mlx_hook (gmlx.win, 2, 1L << 0, &key_handle, &gmlx);
			mlx_hook (gmlx.win, 17, 1L << 2, &handle_close, &gmlx);
			mlx_loop (gmlx.mlx);
		}
		exit (1);
	}
}
