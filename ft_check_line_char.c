/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:35:37 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/15 23:20:33 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_line_char(char *line, int indx, t_game_map *g_game_map)
{
	indx = 0;

	while(line[indx] != '\0')
	{
		if( line[indx] == '0' || line[indx] == '1' || line[indx] == 'C' || line[indx] == 'E' || line[indx] == 'P' || line[indx] == '\n')
		{
			if(line[indx] == 'C')
				g_game_map->collect++;
			if(line[indx] == 'P')
				g_game_map->player++;
			if(line[indx] == 'E')
				g_game_map->way_out++;
		indx++;
		g_game_map->width = indx;
		}
		else
			ft_exiting_prog(1, "invalid character..error\n");
	}
	if(g_game_map->player > 1 || g_game_map->way_out > 1)
		ft_exiting_prog(1, "too many players or exits on the map\n");
}