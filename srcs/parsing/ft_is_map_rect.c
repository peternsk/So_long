/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:49:00 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 17:14:17 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	ft_is_map_rect(int width, t_game_map *game)
{
	int	i;

	i = 0;
	width = ft_strlen(game->map[i]) - 1;
	while (i < game->height)
	{
		printf("game->width: %d\n", game->width);
		printf("width: %d\n", width);
		if (game->width != width)
			return (false);
		i++;
	}
	return (true);
}
