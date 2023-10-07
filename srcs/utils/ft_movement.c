/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:17:38 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/07 14:39:34 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*

 * Draws a new instance of an image, it will then share the same
 * pixel buffer as the image.
 * 
 * NOTE: Keep in mind that the instance array gets reallocated, try
 * to store the return value to the instance! 
 * NOT the pointer! It will become invalid!
 * 
 * WARNING: Try to display as few images on the window as possible,
 * drawing too many images will cause a loss in peformance!
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] img The image to draw on the screen.
 * @param[in] y The X position.
 * @param[in] x The Y position.
 * @return Index to the instance, or -1 on failure.

int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t y, int32_t x);

*/

int	move_check(t_game_map *game, int x, int y)
{
	if (game->map[x][y] == '0')
		return (1);
	if (game->map[x][y] == 'P')
		return (1);
	if (game->map[x][y] == 'C')
	{
		game->collect_maze++;
		game->map[x][y] = '0';
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], y, x);
		return (1);
	}
	if (game->map[x][y] == 'E' && game->collect_maze == game->collect)
	{
		printf("You finished the game in %d steps\n", game->move_cnt);
		mlx_close_window(game->mlx);
	}
	return (0);
}

void	move_up(t_game_map *game)
{
	if (move_check(game, game->player_x - 1, game->player_y))
	{
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], game->player_x, game->player_y);
		mlx_image_to_window(game->mlx, game->arr_img[PLAYER], game->player_x - 1, game->player_y);
		game->player_x--;
		printf("Movement count: %d\n", ++game->move_cnt);
	}
}

void	move_down(t_game_map *game)
{
	if (move_check(game, game->player_x + 1, game->player_y))
	{
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], game->player_x, game->player_y);
		mlx_image_to_window(game->mlx, game->arr_img[PLAYER], game->player_x + 1, game->player_y);
		game->player_x++;
		printf("Movement count: %d\n", ++game->move_cnt);
	}
}

void	move_left(t_game_map *game)
{
	if (move_check(game, game->player_x, game->player_y - 1))
	{
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], game->player_x, game->player_y);
		mlx_image_to_window(game->mlx, game->arr_img[PLAYER], game->player_x, game->player_y - 1);
		game->player_y--;
		printf("Movement count: %d\n", ++game->move_cnt);
	}
}

void	move_right(t_game_map *game)
{
	if (move_check(game, game->player_x, game->player_y + 1))
	{
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], game->player_x, game->player_y);
		mlx_image_to_window(game->mlx, game->arr_img[PLAYER], game->player_x, game->player_y + 1);
		game->player_y++;
		printf("Movement count: %d\n", ++game->move_cnt);
	}
}