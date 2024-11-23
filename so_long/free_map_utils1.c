/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:08:59 by nsan              #+#    #+#             */
/*   Updated: 2024/10/27 17:14:34 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_tmap(t_map *game_map)
{
	free(game_map);
	return (1);
}

int	free_game_map(t_map *game_map)
{
	int	i;

	i = 0;
	while (i < game_map->height)
	{
		free(game_map->map_array[i]);
		i++;
	}
	free(game_map->map_array);
	free(game_map);
	return (1);
}

void	free_copy(char **game_cpy, t_map *game_map)
{
	int	i;

	i = 0;
	while (i < game_map->height)
	{
		free(game_cpy[i]);
		i++;
	}
	free(game_cpy);
}

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}
