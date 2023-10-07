/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_to_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:31:09 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/07 14:39:34 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	mlx_image_t* img;

	img = mlx_texture_to_image(mlx, image_maze->arr_txtur[0]);
	if (!img)
        return(EXIT_FAILURE);
*/

#include "../../so_long.h"

void	ft_texture_to_image(t_game_map *game)
{

	game->arr_img[WALL]  = mlx_texture_to_image(game->mlx, game->arr_txtur[WALL]);
	game->arr_img[FLOOR]  = mlx_texture_to_image(game->mlx, game->arr_txtur[FLOOR]);
	game->arr_img[COLLECT]  = mlx_texture_to_image(game->mlx, game->arr_txtur[COLLECT]);
	game->arr_img[PLAYER]  = mlx_texture_to_image(game->mlx, game->arr_txtur[PLAYER]);
	game->arr_img[WAY_OUT_CLOSE]  = mlx_texture_to_image(game->mlx, game->arr_txtur[WAY_OUT_CLOSE]);
	game->arr_img[WAY_OUT_OPEN]  = mlx_texture_to_image(game->mlx, game->arr_txtur[WAY_OUT_OPEN]);
}