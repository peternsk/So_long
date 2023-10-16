/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:35:37 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 17:13:22 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	ft_check_line_char(t_game_map *game)
{
	int	i;
	int	j;

	i = 0;
    while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0' || game->map[i][j] == '1' || game->map[i][j] == 'C'|| game->map[i][j] == 'E' || game->map[i][j] == 'P' || game->map[i][j] == '\n')
			{
				if (game->map[i][j] == 'C')
					game->collect++;
				if (game->map[i][j] == 'P')
					game->player++;
				if (game->map[i][j] == 'E')
					game->way_out++;
				j++;
				game->width = j;
			}
			else
				return (false);
		}
		i++;
	}
	if (game->player > 1 || game->way_out > 1)
		return (false);
	return (true);
}
