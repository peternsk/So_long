/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_path_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:27:54 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/17 15:11:55 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	ft_is_path_valid(t_game_map *game)
{
	ft_flood_fill(game->player_x, game->player_y, game);
	if ((game->collect != game->collect_flood)
		|| (game->way_out != game->exit_flood))
		return (false);
	return (true);
}
