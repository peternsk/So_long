/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh__img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:50:55 by pnsaka            #+#    #+#             */
/*   Updated: 2023/10/08 12:09:59 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void    ft_refresh_img(t_game_map *game)
{
	mlx_delete_image(game->mlx, game->arr_img[WALL]);
	mlx_delete_image(game->mlx, game->arr_img[FLOOR]);
	mlx_delete_image(game->mlx, game->arr_img[COLLECT]);
	mlx_delete_image(game->mlx, game->arr_img[WAY_OUT_OPEN]);
	mlx_delete_image(game->mlx, game->arr_img[WAY_OUT_CLOSE]);
	mlx_delete_image(game->mlx, game->arr_img[PLAYER]);
}