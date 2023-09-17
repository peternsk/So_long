/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:17 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/17 14:51:54 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_map	*create_game_map(char *file_path)
{
	t_game_map	*game_map;

	game_map = malloc(1 * sizeof(t_game_map));
	if (!game_map)
		return (NULL);
	game_map->map 		= 0;
	game_map->collect 	= 0;
	game_map->player 	= 0;
	game_map->way_out 	= 0;
	game_map->height 	= 0;
	game_map->width 	= 0;
	game_map->indx 		= 0;
	game_map->fd		= open(file_path, O_RDONLY); 
	
	return (game_map);
}

t_flood_maze *create_flood_maze(t_game_map *g_game_map)
{
	t_flood_maze *flood_maze;

	flood_maze = malloc(1 * sizeof(t_flood_maze));
	if(!flood_maze)
		return(NULL);
	flood_maze->x		= 0;
	flood_maze->y		= 0;
	flood_maze->maze	= 0;
	flood_maze->fill	 = '+';
	flood_maze->height 	= g_game_map->height;
	flood_maze->width 	= g_game_map->width;
	flood_maze->collect = 0;
	flood_maze->exit	= 0;
	flood_maze->maze_char = 0; //flood_maze->maze[flood_maze->x][flood_maze->y];

	return(flood_maze);
}