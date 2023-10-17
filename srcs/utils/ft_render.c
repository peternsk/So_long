/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 02:37:51 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/14 02:42:28 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_render(t_game_map * game, int x, int y)
{
	
}
	if (game->map[i][j] == '1')
		mlx_image_to_window(game->mlx, game->arr_img[WALL], x, y);
	else if (game->map[i][j] == '0')
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], x, y);
	else if (game->map[i][j] == 'C')
		mlx_image_to_window(game->mlx, game->arr_img[COLLECT], x, y);
	else if (game->map[i][j] == 'E')
		mlx_image_to_window(game->mlx, game->arr_img[WAY_OUT_CLOSE], x,y);
	else if (game->map[i][j] == 'P')
	{
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], x, y);
		p_x = x;
		p_y = y;
	}
