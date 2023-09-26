/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_path_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:27:54 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/18 13:12:45 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	this function will compare the number of collectibles and the number of exits
	found with the flood fill and what i've found on my original map.
	==> is all my collectibles and exit reacheble ?

	################                                ################
	#0C000000000000#                                #00C00000000000#
	#00000000000000#                                #00000000000000#
	#0000000P000000#             ==>                #0000000P000000#
	#00000000000000#                                #00000000000000#
	#000000000E0000#                                ####000000E0000#
	#C0000000000000#                                #C0#00000000000#
	################                                ################
*/

#include "../so_long.h"

void	ft_is_path_valid(t_game_map *g_game_map, t_flood_maze * g_maze)
{
	ft_flood_fill(g_maze->x, g_maze->y, g_maze);
	
	if(g_game_map->collect != g_maze->collect || g_game_map->way_out != g_maze->exit)
		ft_exiting_prog(1, "unreachebla char");
	else
		printf("valid path\n");
}