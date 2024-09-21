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

#include <mlx.h>


int main(int ac, char** av)
{
    void *mlx_ptr = mlx_init(); //will init the connection between the software and the display
    void *win_ptr = mlx_new_windows(mlx_ptr, 800, 800, "So_Long"); //creating new window for the display
    void *img_ptr = mlx_new_image(mlx_ptr, 20, 20);
    int put_img = mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 40, 40);

    
}