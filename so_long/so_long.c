/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:36:52 by marvin            #+#    #+#             */
/*   Updated: 2024/09/20 11:36:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void map_validation(t_map *game_map)
{
    int flag = 0;
    int i = 0;
    while(i < game_map->height)
    {
        if(game_map->map_array[i][0] == '1' || game_map->map_array[i][game_map->width-1] == '1')
            flag = 1;
        if(i == 0 || i == (game_map->height-1))
        {
            int j = 1;
            while(j < game_map->width)
            {
                if(game_map->map_array[i][j] == '1')
                    flag = 1;
                else
                {
                    flag = 0;
                    break;
                }
                j++;
            }
        }
        i++;
    }
    printf("Flag: %d\n", flag);
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
            if(buffer == 'P')
                game_map->player_count++;
            if(buffer == 'C')
                game_map->collect_count++;
            if(buffer == 'E')
                game_map->exit_count++;
            j++;
        }
        if (i >= game_map->height)
            break;
    }
}


int main(int ac, char** av)
{
    if (ac == 2) {
        int row = 0;
        int col = 0;
        int i = 0;

        int fd_ber = open(av[1], O_RDONLY);
        if (fd_ber < 0) {
            perror(".ber file path could not be opened");
            exit(EXIT_FAILURE);
        }

        char buffer[1024];
        int bytesRead = read(fd_ber, buffer, sizeof(buffer)); 
        buffer[bytesRead] = '\0'; 
        close(fd_ber); 

        while (i < bytesRead) {
            if (buffer[i] == '\n') {
                row++;
            }
            i++;
        }

        i = 0;
        while (buffer[i] != '\n' && buffer[i] != '\0') {
            col++;
            i++;
        }

        printf("Rows: %d, Columns: %d\n", row, col);
        char** map = malloc(sizeof(char*) * row);
        int j = 0;
        while(j < row)
        {
            map[j] = malloc(sizeof(char) * (col + 1)); // +1 for '\0' at the end of each row if needed
            j++;
        }
        t_map game_map;
        game_map.map_array = map;
        game_map.width = col;
        game_map.height = row;
        game_map.collect_count = 0;
        game_map.exit_count = 0;
        game_map.player_count = 0;

        // Reopen the .ber file for reading again
        fd_ber = open(av[1], O_RDONLY);
        if (fd_ber < 0) {
            perror("Error reopening .ber file");
            exit(EXIT_FAILURE);
        }

        // Fill the map array
        fill_map(fd_ber, &game_map);
        map_validation(&game_map);
        close(fd_ber); // Close the file again after filling the map

        // Print the map for testing
        printf("Map content:\n");
        for (int i = 0; i < row; i++) {
            printf("%s\n", game_map->map_array[i]);
        }

        // Free allocated memory
        for (int j = 0; j < row; j++) {
            free(game_map->map_array[j]);
        }
        free(game_map->map_array);
    }
    return 0;
    
}

    
    //put a .ber map file into the 2D array(grid format)
    //validate the map
        //check if the map is rectangular --> have walls, have a player and exit and collectibles
    //after map validation, render to the screen using minilibx
        //will require .xpm files to represent each type of element visually
    //validate the player movements
    //implement win and exit conditions


    //main parts of the project
    //file reading and map parsing
    //validation and error handling
    //game loop and rendering
    //player controls

