/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:21:42 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/09 15:12:26 by pnsaka           ###   ########.fr       */
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


typedef enum mlx_images
{
	PLAYER,
	COLLECT,
	WALL,
	FLOOR,
	WAY_OUT_OPEN,
	WAY_OUT_CLOSE,
	NUM_OF_IMAGE
}	t_mlx_images;

typedef struct s_game_map
{
	char	**map;
	char	**maze;
	int		collect;
	int		player;
	int		way_out;
	int		height;
	int		width;
	int		indx;
	int		fd;
	int		player_x;
	int		player_y;
	int		ext_p_x;
	int		ext_p_y;
	char	fill;
	int		collect_flood;
	int		exit_flood;
	char	maze_char;
	int		move_cnt;

	int collect_maze;
	int exit_maze;
	int floor_maze;
	int player_maze;
	int wall;
	int x_64;
	int y_64;
	
	mlx_texture_t *arr_txtur[NUM_OF_IMAGE];
	mlx_image_t *arr_img[NUM_OF_IMAGE];
	mlx_t *mlx;
	mlx_key_data_t keydata;
	
}			t_game_map;



t_game_map		*create_game_map(char *file_path);

void		ft_check_file_ext(char *map_file, char *req_ext);
void		ft_check_line_char(char *line, int indx, t_game_map *game);
void		ft_map_to_arr(t_game_map *game);
void		ft_check_line_char(char *line, int indx, t_game_map *game);
int			ft_count_line(char *file_path);
void		ft_is_map_close(t_game_map *game);
void		ft_is_map_rect(int width, t_game_map *game);
void		ft_check_mando_char(t_game_map *game);
void		ft_p_position(t_game_map *game);
void		ft_ext_position(t_game_map *game);
void		ft_arr_cpy(t_game_map *game);
void    	ft_flood_fill(int x, int y, t_game_map *game);
void		ft_is_path_valid(t_game_map *game);

//mlx
void		ft_load_png(void *param);
void		ft_arr_texture(t_game_map* image);
void		ft_texture_to_image(t_game_map *game);
void		ft_player_moves(mlx_key_data_t keydata, void* param);
void   		ft_refresh_img(t_game_map *game);

//player move
int			move_check(t_game_map *game, int x, int y);
void		move_up(t_game_map *game);
void		move_down(t_game_map *game);
void		move_left(t_game_map *game);
void		move_right(t_game_map *game);

//assembled functions
int			ft_init(t_game_map *game);

#endif