/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:54:25 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/28 09:18:05 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_arr_cpy(t_game_map *game)
{
	int i = 0;

	game->maze = (char**)malloc(game->height * sizeof(char*));
	if(!game->maze)
		return;
	while(i < game->height)
	{
		game->maze[i] = ft_strdup(game->map[i]);
		//printf("%s\n", game->map[i]);
		i++;
	}
}