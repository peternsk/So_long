/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:04:30 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 10:25:08 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_load_png_utlis(t_game_map *game, t_load_pos *var)
{
	if (game->map[var->i][var->j] == '1')
		mlx_image_to_window(game->mlx, game->arr_img[WALL], var->x, var->y);
	else if (game->map[var->i][var->j] == '0')
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], var->x, var->y);
	else if (game->map[var->i][var->j] == 'C')
		mlx_image_to_window(game->mlx, game->arr_img[COLLECT], var->x, var->y);
	else if (game->map[var->i][var->j] == 'E')
		mlx_image_to_window(game->mlx, game->arr_img[WAY_OUT_CLOSE], var->x,
			var->y);
}

void	ft_load_png(t_game_map *game, t_load_pos *var)
{
	int	p_x;
	int	p_y;

	var->i = -1;
	var->j = -1;
	while (++var->i < game->height)
	{
		while (++var->j < game->width)
		{
			ft_load_png_utlis(game, var);
			if (game->map[var->i][var->j] == 'P')
			{
				mlx_image_to_window(game->mlx, game->arr_img[FLOOR], var->x,
					var->y);
				p_x = var->x;
				p_y = var->y;
			}
			var->x = var->x + 64;
		}
		var->j = -1;
		var->x = 0;
		var->y = var->y + 64;
	}
	mlx_image_to_window(game->mlx, game->arr_img[PLAYER], p_x, p_y);
}
