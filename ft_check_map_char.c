/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:35:37 by peternsaka        #+#    #+#             */
/*   Updated: 2023/08/30 16:13:11 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_char(char *line)
{
	int indx;
	
	indx = 0;
	if( line[indx] == '0' || line[indx] == '1' || line[indx] == 'C' || line[indx] == 'E' || line[indx] == 'P')
		indx++;
	// {
	// 	if(map[indx] == 'C')
	// 		t_game_map->collect++;
	// 	if(map[indx] == 'P')
	// 		t_game_map->player++;
	// 	if(map[indx] == 'E')
	// 		t_game_map->out++;
	// indx++;
	// }
	else
		ft_exiting_prog(1, "not a valid char");
}