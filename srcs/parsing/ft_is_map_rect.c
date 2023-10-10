/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:49:00 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/10 11:25:57 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_is_map_rect(int width, t_game_map *game)
{
	int	i;

	i = 0;
	width = ft_strlen(game->map[i]) - 1;
	while (i < game->height)
	{
		if (game->width == width)
			i++;
		else
			ft_exiting_prog(1, "map not rectangle\n");
	}
	printf("map is rectangle\n");
}
