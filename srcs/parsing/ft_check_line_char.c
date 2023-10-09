/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:35:37 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/09 15:59:09 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_check_line_char(char *line, int indx, t_game_map *game)
{
	indx = 0;

	while (line[indx] != '\0')
	{
		if (line[indx] == '0' || line[indx] == '1' || line[indx] == 'C'
			|| line[indx] == 'E' || line[indx] == 'P' || line[indx] == '\n')
		{
			if (line[indx] == 'C')
				game->collect++;
			if (line[indx] == 'P')
				game->player++;
			if (line[indx] == 'E')
				game->way_out++;
			indx++;
			game->width = indx;
		}
		else
			ft_exiting_prog(1, "invalid character..error\n");
	}
	if (game->player > 1 || game->way_out > 1)
		ft_exiting_prog(1, "too many players or exits on the map\n");
}