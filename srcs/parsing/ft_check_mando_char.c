/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_mando_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:07:13 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/13 15:55:59 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	ft_check_mando_char(t_game_map *game)
{
	int	num_of_player;
	int	num_of_exit;
	int	num_of_collect;

	num_of_player = game->player;
	num_of_exit = game->way_out;
	num_of_collect = game->collect;
	if (num_of_player != 1 && num_of_exit != 1 && num_of_collect <= 0)
		return (false);
	return (true);
}
