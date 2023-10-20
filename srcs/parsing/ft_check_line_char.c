/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:35:37 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/20 11:00:07 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_check_line_char_utils(t_game_map *game, t_load_pos var)
{
	if (game->map[var.i][var.j] == 'C')
		game->collect++;
	if (game->map[var.i][var.j] == 'P')
		game->player++;
	if (game->map[var.i][var.j] == 'E')
		game->way_out++;
	game->width = var.j + 1;
}

bool	ft_check_line_char(t_game_map *game, t_load_pos var)
{
	var.i = -1;
	while (game->map[++var.i] != NULL)
	{
		var.j = -1;
		while (game->map[var.i][++var.j])
		{
			if (game->map[var.i][var.j] == '0' || game->map[var.i][var.j] == '1'
				|| game->map[var.i][var.j] == 'C'
				|| game->map[var.i][var.j] == 'E'
				|| game->map[var.i][var.j] == 'P'
				|| game->map[var.i][var.j] == '\n')
			{
				ft_check_line_char_utils(game, var);
			}
			else
				return (false);
		}
	}
	return (true);
}
