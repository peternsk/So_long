/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:17 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/08 15:12:55 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_map	*create_game_map(char **map, char *file_path)
{
	t_game_map	*game_map;

	game_map = malloc(1 * sizeof(t_game_map));
	if (!game_map)
		return (NULL);
	game_map->map = map;
	game_map->collect = 0;
	game_map->player = 0;
	game_map->way_out = 0;
	game_map->height = 0;
	game_map->lenght = ft_count_line(file_path);
	return (game_map);
}