/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:54:25 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/12 15:11:44 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_arr_cpy(t_game_map *game)
{
	int	i;

	i = 0;
	game->maze = (char **)calloc(game->height + 1, sizeof(char *));
	if (!game->maze)
		ft_free_f(game, "error");
	while (i < game->height)
	{
		game->maze[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->maze[i] = NULL;
}
