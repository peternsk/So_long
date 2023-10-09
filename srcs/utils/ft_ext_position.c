/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ext_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:10:33 by pnsaka            #+#    #+#             */
/*   Updated: 2023/10/09 15:22:47 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_ext_position(t_game_map *game)
{
	int x = 0;
	int y = 0;
	
	while(x < game->height)
	{
		while( y < game->width)
		{
			if(game->map[x][y] == 'E')
			{
				game->ext_p_x = x;
				game->ext_p_y = y;
				break;
			}
			else
				y++;
		}
		y = 0;
	x++;
	}
}