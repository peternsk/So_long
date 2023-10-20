/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_limits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:51:45 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/20 10:26:54 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	ft_map_limits(t_game_map *game)
{
	if (game->height > 21 || game->width > 41)
		return (false);
	if (game->player > 1 || game->way_out > 1)
		return (false);
	return (true);
}
