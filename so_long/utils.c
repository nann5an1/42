/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:09:58 by marvin            #+#    #+#             */
/*   Updated: 2024/10/19 12:09:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_map(t_map *game_map, int row)
{
    printf("Printed map in char** array\n");
    int i = 0;
    while (i < row)
    {
        printf("%s\n", (game_map->map_array)[i]);
        i++;
    }
}

void    error_msg(t_map *g_map)
{
    if(g_map->player_count != 1)
        strfd("Error! There has to be 1 player.\n", 2);
    if(!(g_map->collect_count > 0))
        strfd("Error! Collectible is less than 1.\n", 2);
    if(g_map->exit_count != 1)
        strfd ("Error! There must be 1 Exit.\n", 2);
    if(g_map->outsider >= 1)
        strfd ("Error! Unrelated character in the game map\n", 2);
}
