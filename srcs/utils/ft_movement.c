/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:17:38 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/11 10:38:48 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	move_check(t_game_map *game, int x, int y)
{
	if (game->map[x][y] == '0')
		return (1);
	if (game->map[x][y] == 'P')
		return (1);
	if (game->map[x][y] == 'C')
		return (1);
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
		game->arr_img[PLAYER]->instances[game->collect_maze].y -= 64;
		game->player_x--;
		printf("Movement count: %d\n", ++game->move_cnt);
	}
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		mlx_put_string(game->mlx, "more !!", game->ext_p_x, game->ext_p_y);
		game->map[game->player_x][game->player_y] = '0';
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], 64 * game->player_y
			- 1, 64 * game->player_x);
		mlx_image_to_window(game->mlx, game->arr_img[PLAYER], 64
			* game->player_y - 1, 64 * game->player_x);
		game->collect_maze++;
		if (game->collect == game->collect_maze)
			mlx_image_to_window(game->mlx, game->arr_img[WAY_OUT_OPEN], 64
				* game->ext_p_y, 64 * game->ext_p_x);
	}
}

void	move_down(t_game_map *game)
{
	if (move_check(game, game->player_x + 1, game->player_y))
	{
		game->arr_img[PLAYER]->instances[game->collect_maze].y += 64;
		game->player_x++;
		printf("Movement count: %d\n", ++game->move_cnt);
	}
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		mlx_put_string(game->mlx, "more !!", game->ext_p_x, game->ext_p_y);
		game->map[game->player_x][game->player_y] = '0';
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], 64 * game->player_y
			+ 1, 64 * game->player_x);
		mlx_image_to_window(game->mlx, game->arr_img[PLAYER], 64
			* game->player_y + 1, 64 * game->player_x);
		game->collect_maze++;
		if (game->collect == game->collect_maze)
			mlx_image_to_window(game->mlx, game->arr_img[WAY_OUT_OPEN], 64
				* game->ext_p_y, 64 * game->ext_p_x);
	}
}

void	move_left(t_game_map *game)
{
	if (move_check(game, game->player_x, game->player_y - 1))
	{
		game->arr_img[PLAYER]->instances[game->collect_maze].x -= 64;
		game->player_y--;
		printf("Movement count: %d\n", ++game->move_cnt);
	}
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		mlx_put_string(game->mlx, "more !!", game->ext_p_y, game->ext_p_x);
		game->map[game->player_x][game->player_y] = '0';
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], 64
			* game->player_y, 64 * game->player_x - 1);
		mlx_image_to_window(game->mlx, game->arr_img[PLAYER], 64
			* game->player_y, 64 * game->player_x - 1);
		game->collect_maze++;
		if (game->collect == game->collect_maze)
			mlx_image_to_window(game->mlx, game->arr_img[WAY_OUT_OPEN], 64
				* game->ext_p_y, 64 * game->ext_p_x);
	}
}

void	move_right(t_game_map *game)
{
	if (move_check(game, game->player_x, game->player_y + 1))
	{
		game->arr_img[PLAYER]->instances[game->collect_maze].x += 64;
		game->player_y++;
		printf("Movement count: %d\n", ++game->move_cnt);
	}
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		mlx_put_string(game->mlx, "more !!", game->ext_p_x, game->ext_p_y);
		game->map[game->player_x][game->player_y] = '0';
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], 64
			* game->player_y, 64 * game->player_x + 1);
		mlx_image_to_window(game->mlx, game->arr_img[PLAYER], 64
			* game->player_y, 64 * game->player_x + 1);
		game->collect_maze++;
		if (game->collect == game->collect_maze)
			mlx_image_to_window(game->mlx, game->arr_img[WAY_OUT_OPEN], 64
				* game->ext_p_y, 64 * game->ext_p_x);
	}
}
