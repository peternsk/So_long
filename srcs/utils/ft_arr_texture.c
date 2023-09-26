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

/*

*/

#include "../so_long.h"

void	ft_arr_texture(t_image_maze* image)
{
	mlx_texture_t* texture;
	
	image->arr_txtur[0] = (texture = mlx_load_png("./images/wall_tree.png"));
	image->arr_txtur[1] = (texture = mlx_load_png("./images/grass_2.png"));
	image->arr_txtur[2] = (texture = mlx_load_png("./images/coins.png"));
	image->arr_txtur[3] = (texture = mlx_load_png("./images/player.png"));
	image->arr_txtur[4] = (texture = mlx_load_png("./images/exit_1.png"));
	image->arr_txtur[5] = (texture = mlx_load_png("./images/exit_2.png"));
}

