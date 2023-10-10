/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:25:31 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/10 12:33:01 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_init(t_game_map *game)
{
	mlx_image_t	*img;

	img = NULL;
	game->mlx = mlx_init((game->width * 64), (game->height * 64), "SO_LONG",
			true);
	if (!game->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	ft_arr_texture(game);
	ft_texture_to_image(game);
	ft_load_png(game);
	mlx_key_hook(game->mlx, &ft_player_moves, game);
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, img);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
