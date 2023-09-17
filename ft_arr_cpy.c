/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:54:25 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/17 15:09:32 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_arr_cpy(t_game_map *g_game_map, t_flood_maze *g_maze)
{
	int i = 0;
	int j = 0;

	g_maze->maze = (char**)malloc(g_game_map->height * sizeof(char*));
	if(!g_maze->maze)
		return;
	while(i < g_game_map->height)
	{
		g_maze->maze[i] = ft_strdup(g_game_map->map[i]);
		printf("%s\n", g_game_map->map[i]);
		i++;
	}
}