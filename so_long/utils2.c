/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:26:25 by nsan              #+#    #+#             */
/*   Updated: 2024/10/27 19:11:40 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	width_height_set(t_point *size, t_game *gmlx, t_map *game_map)
{
	size->x = game_map->width;
	size->y = game_map->height;
	gmlx->width = game_map->width;
	gmlx->height = game_map->height;
}

void	cpy_map(char **game_cpy, t_map *game_map)
{
	int		i;
	char	*new_cpy;

	i = 0;
	while (i < game_map->height)
	{
		new_cpy = ft_strdup (game_map->map_array[i]);
		game_cpy[i] = new_cpy;
		i++;
	}
}

int	handle_close(t_game *gmlx)
{
	clean_mlx (gmlx);
	exit (0);
	return (0);
}

void	path_set_err_handle(t_game *gmlx)
{
	int	i;
	int	fd;

	i = -1;
	gmlx->path_array[0] = PLAYER;
	gmlx->path_array[1] = TILE;
	gmlx->path_array[2] = WALL;
	gmlx->path_array[3] = EXIT;
	gmlx->path_array[4] = FOOD;
	while (++i < 5)
	{
		fd = open(gmlx->path_array[i], O_RDONLY);
		if (fd < 0)
		{
			strfd ("File couldn't be opened. Image file name wrong.\n", 2);
			free_gmlx_copy (gmlx);
			close (fd);
			exit (1);
		}
		close (fd);
	}
}
