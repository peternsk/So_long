/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_mando_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:07:13 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/09 15:59:24 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_check_mando_char(t_game_map *game)
{
	int num_of_player = game->player;
	int num_of_exit = game->way_out;
	int num_of_collect = game->collect;

	if (num_of_player == 1 && num_of_exit == 1 && num_of_collect > 0)
		printf("all mando char are in map\n");
	else
		ft_exiting_prog(1, "missing mando char\n");
}