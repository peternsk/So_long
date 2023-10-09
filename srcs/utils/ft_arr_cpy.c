/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:54:25 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/09 15:33:02 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_arr_cpy(t_game_map *game)
{
	int i = 0;

	game->maze = (char **)malloc(game->height * sizeof(char *));
	if (!game->maze)
		return ;
	while (i < game->height)
	{
		game->maze[i] = ft_strdup(game->map[i]);
		i++;
	}
}