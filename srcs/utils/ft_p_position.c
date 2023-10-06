/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:04:57 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/30 07:17:38 by peternsaka       ###   ########.fr       */
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

#include "../so_long.h"

void	ft_p_position(t_game_map *game)
{
	int x = 0;
	int y = 0;
	
	while(x < game->height)
	{
		while( y < game->width)
		{
			if(game->map[x][y] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				break;
			}
			else
				y++;
		}
		y = 0;
	x++;
	}
}