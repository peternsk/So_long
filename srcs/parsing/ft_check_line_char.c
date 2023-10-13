/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:35:37 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/13 16:09:28 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	ft_check_line_char(char *line, t_game_map *game)
{
	int	indx;

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
			return (false);
	}
	if (game->player > 1 || game->way_out > 1)
		return (false);
	return (true);
}
