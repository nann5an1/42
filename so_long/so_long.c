/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:36:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/21 16:59:41 by marvin           ###   ########.fr       */
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
    // else if (g_map->map_array[r][c] == '0')
    // {
    //     begin.count++;
    //     if (begin.count == 1)
    //     {
    //         begin.y = r;
    //         begin.x = c;
    //     }
    // }
    else if (g_map->map_array[r][c] != '1' && g_map->map_array[r][c] != '0')
        g_map->outsider++;
    // error_msg(g_map);
    
}

void is_rectangular(t_map* game_map)
{
    int i;
    int row_len;

    i = 0;
    int expected_width = ft_strlen(game_map->map_array[i]);
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
    error_msg(game_map);
    printf("Player count:%d\nCollectible:%d\nExit:%i\nOutsider:%d\n", game_map->player_count, game_map->collect_count, game_map->exit_count, game_map->outsider);
    
}
void    row_col(int fd_ber)
{
    int row;
    int col;
    char buffer[1024];
    int i;

    i = -1;
    row = 0;
    col = 0;
    int bytesRead = read(fd_ber, buffer, sizeof(buffer)); 
    buffer[bytesRead] = '\0'; 
    close(fd_ber); 
    while (++i < bytesRead)
    {
        if (buffer[i] == '\n')
            row++;
    }
    i = -1;
    while (buffer[++i] != '\n' && buffer[++i] != '\0')
        col++;
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
        int i = -1;
        int fd_ber;
        int len;
        int cmp;
        char** splitted;
        t_point size;
        t_point begin;

        splitted = ft_split (av[1], '.');
        cmp = ft_strncmp(splitted[1], "ber", 3);
        if (cmp == 0)
        {
            fd_ber = open(av[1], O_RDONLY);
            if (fd_ber < 0)
            {
                perror(".ber file path could not be opened");
                exit(EXIT_FAILURE);
            }
        }
        // check_file (av);
        int row;
        int col;
        char buffer[1024];
        row = 0;
        col = 0;
        int bytesRead = read(fd_ber, buffer, sizeof(buffer)); 
        buffer[bytesRead] = '\0'; 
        close(fd_ber); 
        while (++i < bytesRead)
        {
            if (buffer[i] == '\n')
                row++;
        }
        i = -1;
        while (buffer[++i] != '\n' && buffer[i] != '\0')
            col++;
        printf("Rows: %d\nColumns: %d\n", row, col);
        char** map = malloc(sizeof(char*) * row);
        int j = 0;
        while(j < row)
        {
            map[j] = malloc(sizeof(char) * (col + 1));
            j++;
        }
        t_map* game_map = malloc(sizeof(t_map));
        game_map->map_array = map;
        game_map->width = col;
        game_map->height = row;
        game_map->collect_count = 0;
        game_map->exit_count = 0;
        game_map->player_count = 0;
        size.x = col;
        size.y = row;
        m_validate(av, fd_ber, game_map);
        begin_point(map, game_map, &begin);
        print_map(game_map, row);
        // beg_pt(game_map);
        flood_fill(map, size, begin);
        // Print the map for testing
    }
}
    //put a .ber map file into the 2D array(grid format)
    //validate the map
        //check if the map is rectangular --> have walls, have a player and exit and collectibles
    //recursive
    //after map validation, render to the screen using minilibx
        //will require .xpm files to represent each type of element visually
    //validate the player movements
    //implement win and exit conditions

    //main parts of the project
    //file reading and map parsing
    //validation and error handling
    //game loop and rendering
    //player controls

//compiling the program --> ./so_long map.ber