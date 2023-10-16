/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:17 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 10:23:56 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_game_map	*create_game_map(char *file_path)
{
	t_game_map	*game;

	game = malloc(1 * sizeof(t_game_map));
	if (!game)
		return (NULL);
	game->map = 0;
	game->collect = 0;
	game->player = 0;
	game->way_out = 0;
	game->height = ft_count_line(file_path);
	game->width = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->ext_p_x = 0;
	game->ext_p_y = 0;
	game->maze = 0;
	game->collect_flood = 0;
	game->exit_flood = 0;
	game->move_cnt = 0;
	game->collect_maze = 0;
	game->exit_maze = 0;
	game->floor_maze = 0;
	game->player_maze = 0;
	return (game);
}
