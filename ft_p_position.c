/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:04:57 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/15 23:51:24 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	this function help's to find the exact coordinate of a spesific character in the map.
	we'll need this data for initializing the start of the flood fill function.

	ex : 
		const G = [
						  0    1    2    3    4    5    6    7    8
  					0	['#', '#', '#', '#', '#', '#', '#', '#', '#'],
  					1	['#', '-', '-', '-', '#', '-', '-', '-', '#'],
  					2	['#', '-', '-', '-', '#', '-', '-', '-', '#'],
  					3	['#', '-', '-', '#', '-', 'P', '-', '-', '#'],
  					4	['#', '#', '#', '-', '-', '-', '#', '#', '#'],
  					5	['#', '-', '-', '-', '-', '#', '-', '-', '#'],
  					6	['#', '-', '-', '-', '#', '-', '-', '-', '#'],
  					7	['#', '-', '-', '-', '#', '-', '-', '-', '#'],
  					8	['#', '#', '#', '#', '#', '#', '#', '#', '#'],
				];

				i'll start by incrementing row if the char that we are looking for arent there.
				the in the row ill increment collums by collums to find the p.

				then ill assign my incrementation index the respective value of x and y.
*/

#include "so_long.h"

void	ft_p_position(t_game_map *g_game_map, t_flood_maze *g_flood_maze)
{
	int x = 0;
	int y = 0;

	while(x < g_game_map->height)
	{
		while( y < g_game_map->width)
		{
			if(g_game_map->map[x][y] == 'P')
			{
				g_flood_maze->x = x;
				g_flood_maze->y = y;
				printf(" position x : %d", x);
				printf(" position x : %d", y);
			}
			else
				y++;
		}
		y = 0;
	x++;
	}
	printf(" maze position x : %d", g_flood_maze->x);
	printf(" maze position y : %d", g_flood_maze->y);
}