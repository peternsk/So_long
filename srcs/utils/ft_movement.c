/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:17:38 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/09 12:50:27 by pnsaka           ###   ########.fr       */
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
	{
		game->collect_maze++;
		game->map[x][y] = 'P';
		return (1);
	}
	// if (game->collect_maze == game->collect)
	// {
	// 	mlx_image_to_window(game->mlx, game->arr_img[WAY_OUT_OPEN], x, y);
	// }
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
		game->arr_img[PLAYER]->instances[PLAYER].y -= 64;
		game->player_x--;
		printf("Movement count: %d\n", ++game->move_cnt);
	}
}

void	move_down(t_game_map *game)
{
	if (move_check(game, game->player_x + 1, game->player_y))
	{

		game->arr_img[PLAYER]->instances[PLAYER].y += 64;
		game->player_x++;
		printf("Movement count: %d\n", ++game->move_cnt);
	}
}

void	move_left(t_game_map *game)
{
	if (move_check(game, game->player_x, game->player_y - 1))
	{
		game->arr_img[PLAYER]->instances[PLAYER].x -= 64;
		game->player_y--;
		printf("Movement count: %d\n", ++game->move_cnt);
	}
}

void	move_right(t_game_map *game)
{
	if (move_check(game, game->player_x, game->player_y + 1))
	{
		game->arr_img[PLAYER]->instances[PLAYER].x += 64;
		game->player_y++;
		printf("Movement count: %d\n", ++game->move_cnt);
	}
}
