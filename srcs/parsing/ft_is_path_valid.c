/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_path_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:27:54 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/10 11:26:20 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_is_path_valid(t_game_map *game)
{
	ft_flood_fill(game->player_x, game->player_y, game);
	if ((game->collect != game->collect_flood)
		|| (game->way_out != game->exit_flood))
	{
		ft_exiting_prog(1, "unreachebla char\n");
	}
	else
		printf("valid path\n");
}
