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

void    m_validate(char **av, int fd_ber, t_map *game_map)
{
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
    char buffer[1024];
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
    bytesRead = read(fd_ber, buffer, sizeof(buffer)); 
    buffer[bytesRead] = '\0'; 
    close(fd_ber);
    return (bytesRead);
}
