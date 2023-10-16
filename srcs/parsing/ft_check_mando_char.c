/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_mando_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:07:13 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 17:23:25 by pnsaka           ###   ########.fr       */
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
	printf("player %d\n", game->player);
	printf("collect %d\n", game->collect);
	printf("exit %d\n", game->way_out);
	if (num_of_player != 1 || num_of_exit != 1 || num_of_collect <= 0)
		return (false);
	return (true);
}
