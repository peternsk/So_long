/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:42:56 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/09 15:59:40 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_is_map_close(t_game_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		if (i == 0 || i == game->height - 1)
		{
			while (j != game->width - 1)
			{
				if (game->map[i][j] == '1')
					j++;
				else
					ft_exiting_prog(1, "open map..\n");
			}
			i++;
			j = 0;
		}
		if (i > 0 && i < game->height - 1)
		{
			if (game->map[i][j] == '1' && game->map[i][game->width - 1] == '1')
				i++;
			else
				ft_exiting_prog(1, "open map..\n");
		}
	}
	printf("close map\n");
}
