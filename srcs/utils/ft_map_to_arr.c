/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:58:27 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 19:35:06 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	ft_map_to_arr(t_game_map *game, char *file_path, int fd)
{
	int	i;
	
	i = -1;
	(void) file_path;
	game->map = (char **)ft_calloc(game->height + 1, sizeof(char *));
	if (!game->map)
		return (false);
	if(ft_strlen(game->map[0]) == 0)
		return (false);
	while (++i < game->height)
		game->map[i] = get_next_line(fd);
	game->map[i] = NULL;
	return (true);
}
