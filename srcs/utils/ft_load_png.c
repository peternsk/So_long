/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:04:30 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/26 10:28:48 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	this function will load png to texture 
*/

#include "../so_long.h"

void	ft_load_png(mlx_t *mlx, t_game_map *game, t_image_maze *image)
{
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
				mlx_image_to_window(mlx, image->arr_img[0], x, y);
				x = x + 64;
				j++;
			}
			else if(game->map[i][j] == 'P')
			{
				mlx_image_to_window(mlx, image->arr_img[3], x, y);
				x = x + 64;
				j++;
			}
			else if(game->map[i][j] == 'E')
			{
				mlx_image_to_window(mlx, image->arr_img[4], x, y);
				x = x + 64;
				j++;
			}
			else if(game->map[i][j] == 'C')
			{
				mlx_image_to_window(mlx, image->arr_img[2], x, y);
				x = x + 64;
				j++;
			}
			else if(game->map[i][j] == '0')
			{
				mlx_image_to_window(mlx, image->arr_img[1], x, y);
				x = x + 64;
				j++;
			}
		}
		i++;
		j = 0;
		x = 0;
		y = y + 64;
	}
}