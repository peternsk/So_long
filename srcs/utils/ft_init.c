/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:25:31 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/28 09:18:05 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/

#include "../so_long.h"

void	ft_init(mlx_t *mlx, t_game_map *game)
{
	mlx_init((game->width *64), (game->height *64), "SO_LONG", true);
	if(!mlx)
		ft_exiting_prog(1, "init error\n");
}