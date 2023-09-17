/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:29 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/17 15:13:16 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
   t_game_map *g_game_map;
   t_flood_maze *g_maze;

	int i;

	i = -1;
	int k = 0;
	
	g_game_map = create_game_map(argv[1]);
	g_maze = create_flood_maze(g_game_map);
	
	g_game_map->height = ft_count_line(argv[1]);
	g_game_map->map = (char**)malloc(g_game_map->height * sizeof(char*));
	if (!g_game_map->map)
 		return (0);
	ft_check_file_ext(argv[1], ".ber");
	ft_map_to_arr(g_game_map);
	ft_is_map_close(g_game_map);
	ft_is_map_rect(g_game_map->width, g_game_map);
	ft_check_mando_char(g_game_map);
	ft_p_position(g_game_map, g_maze);
	ft_arr_cpy(g_game_map, g_maze);
	ft_is_path_valid(g_maze->x, g_maze->y, g_maze->maze, g_maze->fill, g_maze->height, g_maze->width, g_maze);
	printf("collect : %d\n", g_maze->collect);

	return(0);
}