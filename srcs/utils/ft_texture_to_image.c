/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_to_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:31:09 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/28 10:00:26 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	mlx_image_t* img;

	img = mlx_texture_to_image(mlx, image_maze->arr_txtur[0]);
	if (!img)
        return(EXIT_FAILURE);
*/

#include "../so_long.h"

void	ft_texture_to_image(t_game_map *game)
{

	game->arr_img[0]  = mlx_texture_to_image(game->mlx, game->arr_txtur[WALL]);
	game->arr_img[1]  = mlx_texture_to_image(game->mlx, game->arr_txtur[FLOOR]);
	game->arr_img[2]  = mlx_texture_to_image(game->mlx, game->arr_txtur[COLLECT]);
	game->arr_img[3]  = mlx_texture_to_image(game->mlx, game->arr_txtur[PLAYER]);
	game->arr_img[4]  = mlx_texture_to_image(game->mlx, game->arr_txtur[WAY_OUT_CLOSE]);
	game->arr_img[5]  = mlx_texture_to_image(game->mlx, game->arr_txtur[WAY_OUT_OPEN]);
}