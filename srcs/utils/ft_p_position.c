/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:04:57 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/09 15:31:28 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_p_position(t_game_map *game)
{
	int x = 0;
	int y = 0;

	while (x < game->height)
	{
		while (y < game->width)
		{
			if (game->map[x][y] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				break ;
			}
			else
				y++;
		}
		y = 0;
		x++;
	}
}