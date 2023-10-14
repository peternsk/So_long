/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:25:31 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/13 23:53:32 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_init(t_game_map *game)
{
	int			i;
	int			j;
	int			x;
	int			y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	game->mlx = mlx_init((game->width * 64), (game->height * 64), "SO_LONG",
			true);
	if (!game->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	ft_arr_texture(game);
	ft_texture_to_image(game);
	ft_load_png(game, i, j, x, y);
	mlx_key_hook(game->mlx, &ft_player_moves, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
