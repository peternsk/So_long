/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_to_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:31:09 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/26 09:14:05 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	mlx_image_t* img;

	img = mlx_texture_to_image(mlx, image_maze->arr_txtur[0]);
	if (!img)
        return(EXIT_FAILURE);
*/

#include "../so_long.h"

void	ft_texture_to_image(t_image_maze *image, mlx_image_t *img, mlx_t* mlx)
{	

	image->arr_img[0] = (img = mlx_texture_to_image(mlx, image->arr_txtur[0]));
	image->arr_img[1] = (img = mlx_texture_to_image(mlx, image->arr_txtur[1]));
	image->arr_img[2] = (img = mlx_texture_to_image(mlx, image->arr_txtur[2]));
	image->arr_img[3] = (img = mlx_texture_to_image(mlx, image->arr_txtur[3]));
	image->arr_img[4] = (img = mlx_texture_to_image(mlx, image->arr_txtur[4]));
	image->arr_img[5] = (img = mlx_texture_to_image(mlx, image->arr_txtur[5]));
}
