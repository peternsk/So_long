/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:17 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/08 12:35:30 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_game_map	*create_game_map(char *file_path)
{
	t_game_map	*game;

	game = malloc(1 * sizeof(t_game_map));
	if (!game)
		return (NULL);
	game->map 		= 0;
	game->collect 	= 0;
	game->player 	= 0;
	game->way_out 	= 0;
	game->height 	= ft_count_line(file_path);
	game->width 	= 0;
	game->indx 		= 0;
	game->fd		= open(file_path, O_RDONLY); 
	

	game->player_x			= 0;
	game->player_y			= 0;
	game->maze		= 0;
	game->fill       = '+';
	game->collect_flood	= 0;
	game->exit_flood	= 0;
	game->maze_char	= 0;
	game->move_cnt = 0;

	game->collect_maze	= 0;;
	game->exit_maze		= 0;
	game->floor_maze	= 0;
	game->player_maze	= 0;
	game->wall	= 0;
	game->x_64		= 64;
	game->y_64		= 64;
	
	return (game);
}
