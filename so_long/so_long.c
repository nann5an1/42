/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:36:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/21 23:14:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void border_check(t_map *game_map)
{
    int flag = 1;
    int i = 0;
    //check for first and last rows
    while(i < game_map->width)
    {
        if(game_map->map_array[0][i] != '1' || game_map->map_array[game_map->height-1][i] != '1')
        {
            flag = 0;
            break;
        }
        i++;
    }
    i = 1;
    //check for first and last columns
    while(i < game_map->height - 1)
    {
        if(game_map->map_array[i][0] != '1' || game_map->map_array[i][game_map->width-1] != '1')
        {
            flag = 0;
            break;
        }
        i++;
   }
   if (!flag)
    strfd("The game map is not a full proper border\n", 2);
}

void ch_validate(int r, int c, t_map *g_map)
{
    t_point begin;
    if (g_map->map_array[r][c] == 'P')
        g_map->player_count++;
    else if (g_map->map_array[r][c] == 'C')
        g_map->collect_count++;
    else if (g_map->map_array[r][c] == 'E')
        g_map->exit_count++;
    else if (g_map->map_array[r][c] != '1' && g_map->map_array[r][c] != '0')
        g_map->outsider++;
}

void is_rectangular(t_map* game_map)
{
    int i;
    int row_len;

    i = 0;
    int expected_width = ft_strlen(game_map->map_array[i]) + (i == game_map->height - 1);
    while(++i < game_map->height)
    {
        row_len = ft_strlen(game_map->map_array[i]);
        if(row_len != expected_width)
        {
            perror("\nMap is not a rectangle");
            exit(EXIT_FAILURE);
        }
    }
}

void fill_map(int fd, t_map *game_map)
{
    char buffer;
    int i = 0;
    int j = 0;

    while (read(fd, &buffer, 1) > 0)
    {
        if (buffer == '\n')
        {
            i++;
            j = 0;
            // printf("%d\n", i);
        }
        else
        {
            game_map->map_array[i][j] = buffer;
            if (i >= 1 && i <= game_map->height - 2)
            {
                if (j >= 1 && j <= game_map->width - 2)
                    ch_validate (i, j, game_map);
            } 
            j++;
        }
        if (i >= game_map->height)
            break;
    }
    print_map(game_map, game_map->height);
    error_msg(game_map);
    printf("Player count:%d\nCollectible:%d\nExit:%i\nOutsider:%d\n", game_map->player_count, game_map->collect_count, game_map->exit_count, game_map->outsider);
    
}

void    begin_point(char **map, t_map *g_map, t_point *begin)
{
    int i;
    int j;
    
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
                printf("The pos of P:( %d, %d )\n", begin->y, begin->x);
                return ;
            }
            i++;
        }
        j++;
    }
    
}
int main(int ac, char** av)
{
    if (ac == 2)
    {
        int fd_ber;
        int bytesRead;
        char buffer[4096];
        t_map *game_map;

        fd_ber = file_validate (av);
        bytesRead = read(fd_ber, buffer, sizeof(buffer)); 
        buffer[bytesRead] = '\0';
        close(fd_ber);
        g_struct(av, game_map, bytesRead, buffer);
    }
}
