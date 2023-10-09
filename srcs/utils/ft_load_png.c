/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:04:30 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/09 12:45:44 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_load_png(void *param)
{
	t_game_map	*game;
	int			i;
	int			j;
	int			x;
	int			y;
	int			p_x;
	int			p_y;
	
	game = param;
	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i < game->height)
	{
		while (j < game->width)
		{
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->arr_img[WALL], x, y);
			else if (game->map[i][j] == '0')
				mlx_image_to_window(game->mlx, game->arr_img[FLOOR], x, y);
			else if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->arr_img[COLLECT], x, y);
			else if (game->map[i][j] == 'E')			
				mlx_image_to_window(game->mlx, game->arr_img[WAY_OUT_CLOSE], x, y);
			else if (game->map[i][j] == 'P')
			{
				mlx_image_to_window(game->mlx, game->arr_img[FLOOR], x, y);
				p_x = x;
				p_y = y;
			}
			x = x + 64;
			j++;
		}
		i++;
		j = 0;
		x = 0;
		y = y + 64;
	}
	mlx_image_to_window(game->mlx, game->arr_img[PLAYER], p_x, p_y);
}
