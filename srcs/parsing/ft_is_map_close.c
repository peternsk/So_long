/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:42:56 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/28 09:18:05 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
	this function verify if my map is close. that means that there's 1s all arround
	the map.

	rep :
			111111111111111
			1             1
			1             1
			1             1
			1             1
			1             1
			1             1
			1             1
			111111111111111

		my strategie will be:
							=> loop throgh my first line to verify that they are all 1s
							=> make a comparation with my last line
							=> itterate in the lines in between to make sure that they are all start 
								and ends with 1s.
*/

#include "../so_long.h"

void	ft_is_map_close(t_game_map *game)
{
	int i = 0;
	int j = 0;

	while(i < game->height)
	{
		if(i == 0 || i == game->height - 1)
		{
			while(j != game->width - 1)
			{
				if(game->map[i][j] == '1')
					j++;
				else
					ft_exiting_prog(1, "open map..\n");
			}
			i++;
			j = 0;
		}
		if(i > 0 && i < game->height - 1) 
		{
			if(game->map[i][j] == '1' && game->map[i][game->width - 1] == '1')
				i++;
			else
				ft_exiting_prog(1, "open map..\n");
		}
	}
	printf("close map\n");
}

