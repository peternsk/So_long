/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:58:42 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/08 19:58:19 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	typedef struct mlx_image
	{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	size_t			count;
	bool			enabled;
	void*			context;
	}	mlx_image_t;


	void ft_hook(void* param)
	{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);                      ====> the function + key to close the window
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))       ====> the keys ill use to move the image (player)
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
	} 

	mlx_loop_hook(mlx, ft_hook, mlx); ===> in main <===

 	* Generic loop hook for any custom hooks to add to the main loop. 
 	* Executes a function per frame, so be careful.
 	* 
 	* @param[in] mlx The MLX instance handle.
 	* @param[in] f The function.
 	* @param[in] param The parameter to pass on to the function.
 	* @returns Whether or not the hook was added successfully. s
	bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param);
*/

#include "../so_long.h"

void	ft_player_moves(mlx_key_data_t keydata, void* param)
{
	t_game_map	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
		move_up(game);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
		move_down(game);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		move_right(game);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
		move_left(game);
	//ft_load_png(game);
}
