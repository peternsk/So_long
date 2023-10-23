/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:08:55 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/18 10:13:21 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_flood_fill(int x, int y, t_game_map *game)
{
	if (game->maze[x][y] == 'C')
		game->collect_flood++;
	if (game->maze[x][y] == 'E')
	{
		game->maze[x][y] = '1';
		game->exit_flood++;
	}
	if (game->maze[x][y] == '1' || game->maze[x][y] == '+')
		return ;
	game->maze[x][y] = '+';
	ft_flood_fill(x, y + 1, game);
	ft_flood_fill(x, y - 1, game);
	ft_flood_fill(x + 1, y, game);
	ft_flood_fill(x - 1, y, game);
}
