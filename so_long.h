/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:21:42 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/26 09:14:27 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <string.h>

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

#define WIDTH	1080
#define HEIGHT	540

typedef struct s_game_map
{
	char	**map;
	int		collect;
	int		player;
	int		way_out;
	int		height;
	int		width;
	int		indx;
	int		fd;
	
}			t_game_map;

typedef	struct s_flood_maze
{
	int		x;
	int		y;
	char	**maze;
	char	fill;
	int		height;
	int		width;
	int		collect;
	int		exit;
	char	maze_char;	

}			t_flood_maze;

typedef struct s_image_maze
{
	int collect;
	int exit;
	int floor;
	int player;
	int wall;
	int x_64;
	int y_64;
	mlx_texture_t *arr_txtur[6];
	mlx_image_t *arr_img[6];
	
}			t_image_maze;


t_game_map		*create_game_map(char *file_path);
t_flood_maze 	 *create_flood_maze(t_game_map *g_game_map);
t_image_maze 	* create_image_maze();


void		ft_check_file_ext(char *map_file, char *req_ext);
void		ft_check_line_char(char *line, int indx, t_game_map *g_game_map);
void		ft_map_to_arr(t_game_map *g_game_map);
void		ft_check_line_char(char *line, int indx, t_game_map *g_game_map);
int			ft_count_line(char *file_path);
void		ft_is_map_close(t_game_map *g_game_map);
void		ft_is_map_rect(int width, t_game_map *g_game_map);
void		ft_check_mando_char(t_game_map *g_game_map);
void		ft_p_position(t_game_map *g_game_map, t_flood_maze *g_flood_maze);
void		ft_arr_cpy(t_game_map *g_game_map, t_flood_maze *g_maze);
void    	ft_flood_fill(int x, int y, t_flood_maze *maze);
void		ft_is_path_valid(t_game_map *g_game_map, t_flood_maze * g_maze);

//mlx
void		ft_load_png(mlx_t *mlx, t_game_map *game, t_image_maze *image);
void		ft_arr_texture(t_image_maze* image);
void		ft_texture_to_image(t_image_maze *image, mlx_image_t *img, mlx_t* mlx);

#endif