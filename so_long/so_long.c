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

int main(int ac, char** av)
{
    // void *mlx_ptr = mlx_init(); //will init the connection between the software and the display
    // void *win_ptr = mlx_new_windows(mlx_ptr, 800, 800, "So_Long"); //creating new window for the display
    // void *img_ptr = mlx_new_image(mlx_ptr, 20, 20);
    // int put_img = mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 40, 40);

    if(ac == 2)
    {
        int fd_ber = open(av[1], O_RDONLY);
        if(fd_ber < 0)
        {
            perror(".ber file path could not be opened");
            exit(EXIT_FAILURE);
        }
        char buffer[1024];
        int bytesRead = read(fd_ber, buffer, sizeof(buffer));
        buffer[bytesRead] = '\0';
        
        //printf("Bytes read:%d\n", bytesRead);
        printf("Content:\n%s", buffer);
        close(fd_ber);
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

}