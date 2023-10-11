/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:11:16 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/11 13:22:37 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_arr_texture(t_game_map *game)
{
	game->arr_txtur[WALL] = mlx_load_png("./images/tree_shadow.png");
	game->arr_txtur[FLOOR] = mlx_load_png("./images/grass_2.png");
	game->arr_txtur[COLLECT] = mlx_load_png("./images/coins.png");
	game->arr_txtur[PLAYER] = mlx_load_png("./images/player.png");
	game->arr_txtur[WAY_OUT_CLOSE] = mlx_load_png("./images/exit_1.png");
	game->arr_txtur[WAY_OUT_OPEN] = mlx_load_png("./images/exit_2.png");
	if (!game->arr_txtur[WALL] || !game->arr_txtur[FLOOR] || !game->arr_txtur[COLLECT] || !game->arr_txtur[PLAYER] || !game->arr_txtur[WAY_OUT_CLOSE] || !game->arr_txtur[WAY_OUT_OPEN])
	{
		ft_free_f(game);
	}
}

