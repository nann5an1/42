/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:09:33 by nsan              #+#    #+#             */
/*   Updated: 2024/10/27 17:12:55 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_gmlx_copy(t_game *gmlx)
{
	int	i;

	i = 0;
	while (i < gmlx->height)
	{
		free(gmlx->map_arr[i]);
		i++;
	}
	free (gmlx->map_arr);
}

void	clean_mlx(t_game *gmlx)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(gmlx->mlx, gmlx->img_arr[i]);
		i++;
	}
	free_gmlx_copy (gmlx);
	mlx_clear_window(gmlx->mlx, gmlx->win);
	mlx_destroy_window(gmlx->mlx, gmlx->win);
	mlx_destroy_display(gmlx->mlx);
	free(gmlx->mlx);
}
