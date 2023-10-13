/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_rnd_pars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:25:44 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/13 00:41:57 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	second_rnd_pars(t_game_map *game)
{
	ft_p_position(game);
	ft_ext_position(game);
	if(ft_arr_cpy(game) == false)
		ft_free_f(game, "allocation error of maze");
	if(ft_is_path_valid(game) == false)
		ft_free_f(game, "unreachable collectible or exit");
	return(true);
}