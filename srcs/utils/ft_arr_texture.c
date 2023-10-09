/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:11:16 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/25 19:46:55 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_arr_texture(t_game_map *image)
{
	mlx_texture_t	*texture;

	image->arr_txtur[WALL] = (texture = mlx_load_png("./images/tree_shadow.png"));
	image->arr_txtur[FLOOR] = (texture = mlx_load_png("./images/grass_2.png"));
	image->arr_txtur[COLLECT] = (texture = mlx_load_png("./images/coins.png"));
	image->arr_txtur[PLAYER] = (texture = mlx_load_png("./images/player.png"));
	image->arr_txtur[WAY_OUT_CLOSE] = (texture = mlx_load_png("./images/exit_1.png"));
	image->arr_txtur[WAY_OUT_OPEN] = (texture = mlx_load_png("./images/exit_2.png"));
}
