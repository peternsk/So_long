/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:04:30 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/07 13:28:42 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	this function will load png to texture 
*/

#include "../so_long.h"

void	ft_load_png(void *param)
{
	t_game_map *game;
	game = param;

	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;


	while(i < game->height)
	{
		while(j < game->width)
		{
			if(game->map[i][j] == '1')
			{
				//mlx_delete_image(game->mlx, game->arr_img[WALL]);
				mlx_image_to_window(game->mlx, game->arr_img[WALL], x, y);
			}
			else if(game->map[i][j] == '0')
				mlx_image_to_window(game->mlx, game->arr_img[FLOOR], x, y);
			else if(game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->arr_img[COLLECT], x, y);
			else if(game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx, game->arr_img[PLAYER], x, y);
			else if(game->map[i][j] == 'E')
			{
				if(game->collect_maze == game->collect_flood)
					mlx_image_to_window(game->mlx, game->arr_img[WAY_OUT_OPEN], x, y);
				else
					mlx_image_to_window(game->mlx, game->arr_img[WAY_OUT_CLOSE], x, y);
			}
			x = x + 64;
			j++;
		}
		i++;
		j = 0;
		x = 0;
		y = y + 64;
	}
}