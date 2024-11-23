/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:26:02 by nsan              #+#    #+#             */
/*   Updated: 2024/10/27 20:04:28 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_init(t_game *gmlx)
{
	int	i;

	i = -1;
	path_set_err_handle (gmlx);
	gmlx->mlx = mlx_init();
	while (++i < 5)
		gmlx->img_arr[i] = mlx_xpm_file_to_image(gmlx->mlx, \
		gmlx->path_array[i], &gmlx->img_w, &gmlx->img_h);
	if (gmlx->mlx == NULL)
	{
		strfd ("Failed to initialize mlx_ptr\n", 2);
		return ;
	}
	gmlx->win = mlx_new_window(gmlx->mlx, gmlx->width * 45, \
	gmlx->height * 45, "so_long");
	if (gmlx->win == NULL)
	{
		strfd ("Failed to initialize window\n", 2);
		return ;
	}
}

void	render_helper(t_game *gmlx, int i, int j)
{
	if (gmlx->map_arr[i][j] == 'P')
		mlx_put_image_to_window(gmlx->mlx, gmlx->win, \
		gmlx->img_arr[0], j * 45, i * 45);
	else if (gmlx->map_arr[i][j] == '0')
		mlx_put_image_to_window(gmlx->mlx, gmlx->win, \
		gmlx->img_arr[1], j * 45, i * 45);
	else if (gmlx->map_arr[i][j] == '1')
		mlx_put_image_to_window(gmlx->mlx, gmlx->win, \
		gmlx->img_arr[2], j * 45, i * 45);
	else if (gmlx->map_arr[i][j] == 'E')
		mlx_put_image_to_window(gmlx->mlx, gmlx->win, \
		gmlx->img_arr[3], j * 45, i * 45);
	else if (gmlx->map_arr[i][j] == 'C')
		mlx_put_image_to_window(gmlx->mlx, gmlx->win, \
		gmlx->img_arr[4], j * 45, i * 45);
}

void	render_map(t_game *gmlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < gmlx->height)
	{
		j = -1;
		while (++j < gmlx->width)
		{
			render_helper (gmlx, i, j);
		}
	}
}
