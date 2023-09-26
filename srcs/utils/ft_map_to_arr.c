/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:58:27 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/20 00:40:59 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_to_arr(t_game_map *g_game_map)
{
	int i;

	i = -1;
	if(g_game_map->fd == -1)
		ft_exiting_prog(1, "error...non-existant or empty file\n");
	else
		printf("file openned\n");
	while(++i < g_game_map->height)
	{
		g_game_map->map[i] = get_next_line(g_game_map->fd);
		ft_check_line_char(g_game_map->map[i], g_game_map->indx, g_game_map);
		//printf("%s\n", g_game_map->map[i]);
	}
}