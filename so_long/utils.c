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

int file_validate(char **av)
{
    char** splitted;
    int fd_ber;

    splitted = ft_split (av[1], '.');
    if (ft_strncmp(splitted[1], "ber", 3) == 0)
    {
        fd_ber = open(av[1], O_RDONLY);
        if (fd_ber < 0)
        {
            perror(".ber file path could not be opened");
            exit (1);
        }
    }
    return (fd_ber);
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

void    m_validate(char **av, t_map *game_map)
{   
    int fd_ber;
    fd_ber = open(av[1], O_RDONLY);
    if (fd_ber < 0)
    {
        perror("Error reopening .ber file");
        exit(EXIT_FAILURE);
    }
    fill_map(fd_ber, game_map);   //has char validation inside
    is_rectangular(game_map);
    border_check(game_map);
    close(fd_ber);
}

int check_file(char **av)
{
    int cmp;
    char** splitted;
    int fd_ber;
    char buffer[4096];
    int bytesRead;

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
    return (bytesRead);
}
void  **row_col(int bytes_read, char *buffer, t_map *g_map)
{
    int i;
    int row;
    int col;
    t_point *size;

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
    col--;
    if (row <= 2)
    {
        perror ("The map must have at least 3 rows.\n");
        exit (1);
    }
    printf("Rows: %d\nColumns: %d\n", row, col);
    g_map->width = col;
    g_map->height = row;
}

char **map_array_alloc(t_map *game_map)
{
    int j;
    char **map;

    j = -1;
    map = malloc(sizeof(char*) * game_map->height);
    while(++j < game_map->height)
        map[j] = malloc(sizeof(char) * (game_map->width + 1));
    game_map->map_array = map;
    game_map->collect_count = 0;
    game_map->exit_count = 0;
    game_map->player_count = 0;
    return (map);
}

void    fill (char **tab, t_point size, t_point cur)
{
    if (size.x < 0 || cur.x >= size.x || size.y < 0 || cur.y >= size.y || \
    (tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'P' && tab[cur.y][cur.x] != '0' && \
    tab[cur.y][cur.x] != 'E'))
        return ;
    tab[cur.y][cur.x] = 'F';
    fill(tab, size, (t_point){cur.x - 1, cur.y});
    fill(tab, size, (t_point){cur.x + 1, cur.y});
    fill(tab, size, (t_point){cur.x, cur.y - 1});
    fill(tab, size, (t_point){cur.x, cur.y + 1});
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
    printf("Starting point for flood fill: y = %d, x = %d\n", begin.y, begin.x);
	fill(tab, size, begin);
    int i = -1;
    while (++i < size.y)
        printf("%s\n", tab[i]);
    i = 0;
    int j;
    while (++i < size.y - 2)
    {   
        j = 0;
        while (++j < size.x - 2)
        {
            if (tab[i][j] == 'E' || tab[i][j] == 'C')
            {
                printf("Not a valid map\n");
                return ;
            }
        }
    }
}

void g_struct(char **av, t_map *game_map, int bytesRead, char *buffer)
{
    t_point size;
    t_point begin;
    char **map;

    game_map = malloc(sizeof(t_map));
    row_col(bytesRead, buffer, game_map);
    map = map_array_alloc(game_map);
    size.x = game_map->width;
    size.y = game_map->height;
    m_validate(av, game_map);
    begin_point(map, game_map, &begin);
    print_map(game_map, game_map->height);
    flood_fill(map, size, begin);
}

