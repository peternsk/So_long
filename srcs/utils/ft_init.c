/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:25:31 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/18 15:16:39 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_init(t_game_map *game)
{
	t_load_pos	var;

	var.i = 0;
	var.j = 0;
	var.x = 0;
	var.y = 0;
	game->mlx = mlx_init((game->width * 64), (game->height * 64), "SO_LONG", false);
	if (!game->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	ft_arr_texture(game);
	ft_texture_to_image(game);
	ft_load_png(game, &var);
	mlx_key_hook(game->mlx, &ft_player_moves, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
