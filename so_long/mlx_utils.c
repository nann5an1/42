/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:15:58 by nsan              #+#    #+#             */
/*   Updated: 2024/10/27 20:04:10 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *gmlx)
{
	int	i;
	int	j;

	i = 0;
	gmlx->collectibles = 0;
	gmlx->moves = 0;
	while (i < gmlx->height)
	{
		j = 0;
		while (j < gmlx->width)
		{
			if (gmlx->map_arr[i][j] == 'P')
			{
				gmlx->init_y = i;
				gmlx->init_x = j;
			}
			else if (gmlx->map_arr[i][j] == 'C')
				gmlx->collectibles++;
			j++;
		}
		i++;
	}
	ft_printf("<<< Total Collectibles >>> %d <<<\n", gmlx->collectibles);
}

int	is_walkable(t_game *gmlx, int new_x, int new_y)
{
	if (gmlx->map_arr[new_y][new_x] == '1')
		return (1);
	else if (gmlx->map_arr[new_y][new_x] == 'C')
	{
		gmlx->collectibles--;
		ft_printf("<<< Collectible Left >>> %d\n", gmlx->collectibles);
		gmlx->map_arr[new_y][new_x] = '0';
	}
	else if (gmlx->map_arr[new_y][new_x] == 'E')
	{
		if (gmlx->collectibles != 0)
		{
			ft_printf("<<< Make sure to collect everything >>>\n");
			return (1);
		}
		ft_printf("<<< YAY!!! YOU WON THE GAME! >>>\n");
		clean_mlx(gmlx);
		exit (0);
	}
	return (0);
}

void	move_player(t_game *gmlx, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = gmlx->init_x + x;
	new_y = gmlx->init_y + y;
	if (new_x < 0 || new_x >= gmlx->width || new_y < 0 || new_y >= gmlx->height)
		return ;
	if (is_walkable(gmlx, new_x, new_y) == 0)
	{
		gmlx->map_arr[gmlx->init_y][gmlx->init_x] = '0';
		gmlx->map_arr[new_y][new_x] = 'P';
		gmlx->init_x = new_x;
		gmlx->init_y = new_y;
		gmlx->moves++;
		ft_printf("Moves: %d\n", gmlx->moves);
		render_map(gmlx);
	}
}

int	key_handle(int key, t_game *gmlx)
{
	if (key == KEY_W || key == KEY_UP)
		move_player(gmlx, 0, -1);
	else if (key == KEY_A || key == KEY_LEFT)
		move_player (gmlx, -1, 0);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player (gmlx, 0, 1);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player (gmlx, 1, 0);
	else if (key == KEY_ESC)
	{
		clean_mlx(gmlx);
		exit (0);
	}
	return (0);
}
