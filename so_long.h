/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:21:42 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/17 15:12:42 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>



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


t_game_map	*create_game_map(char *file_path);
t_flood_maze *create_flood_maze(t_game_map *g_game_map);

void		ft_check_file_ext(char *map_file, char *req_ext);
void		ft_map_to_arr(t_game_map *g_game_map);
void		ft_check_line_char(char *line, int indx, t_game_map *g_game_map);
int			ft_count_line(char *file_path);
void		ft_is_map_close(t_game_map *g_game_map);
void		ft_is_map_rect(int width, t_game_map *g_game_map);
void		ft_check_mando_char(t_game_map *g_game_map);
void		ft_p_position(t_game_map *g_game_map, t_flood_maze *g_flood_maze);
void		ft_arr_cpy(t_game_map *g_game_map, t_flood_maze *g_maze);
void		ft_is_path_valid(int x, int y, char **map, char fill, int height, int width, t_flood_maze *maze);


#endif