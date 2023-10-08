/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:25:31 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/08 12:27:55 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_init(mlx_t *mlx, t_game_map *game)
{
	mlx_init((game->width *64), (game->height *64), "SO_LONG", true);
	if(!mlx)
		ft_exiting_prog(1, "init error\n");
}