/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:19:55 by nsan              #+#    #+#             */
/*   Updated: 2024/10/27 20:19:57 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include <sys/types.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define EXIT "img/exit.xpm"
# define TILE "img/tile.xpm"
# define PLAYER "img/player.xpm"
# define FOOD "img/food.xpm"
# define WALL "img/wall.xpm"

typedef struct s_game
{
	int		moves;
	int		collectibles;
	int		img_w;
	int		img_h;
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	char	**map_arr;
	int		init_x;
	int		init_y;
	char	*path_array[5];
	void	*img_arr[5];
}	t_game;

typedef struct s_map
{
	char	**map_array;
	int		width;
	int		height;
	int		collect_count;
	int		exit_count;
	int		player_count;
	int		outsider;
}	t_map;

typedef struct f_point
{
	int	x;
	int	y;
}	t_point;

int		fill_map(int fd, t_map *game_map);
int		border_check(t_map *game_map);
void	ch_validate(int r, int c, t_map *g_map);
int		is_rectangular(t_map *game_map);
int		error_msg(t_map *g_map);
int		m_validate(char **av, t_map *game_map);
int		flood_fill(char **tab, t_point size, t_point begin);
void	fill(char **tab, t_point size, t_point cur);
int		file_validate(char **av);
int		row_col(int bytes_read, char *buffer, t_map *g_map);
void	map_array_alloc(t_map *game_map);
int		game_struct(t_game *game, char **av, int bytesRead, char *buffer);
void	begin_point(char **map, t_map *g_map, t_point *begin);
int		free_tmap(t_map *game_map);
int		free_game_map(t_map *game_map);
void	cpy_map(char **game_cpy, t_map *game_map);
void	free_copy(char **game_cpy, t_map *game_map);
void	win_init(t_game *gmlx);
void	find_player(t_game *gmlx);
int		key_handle(int key, t_game *gmlx);
void	render_map(t_game *gmlx);
void	free_gmlx_copy(t_game *gmlx);
void	clean_mlx(t_game *gmlx);
void	width_height_set(t_point *size, t_game *gmlx, t_map *game_map);
int		handle_close(t_game *gmlx);
void	path_set_err_handle(t_game *gmlx);
void	free_split(char **splitted);

#endif