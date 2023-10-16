/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:58:27 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 15:41:39 by pnsaka           ###   ########.fr       */
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
	while (++i < game->height)
		game->map[i] = get_next_line(fd);
	game->map[i] = NULL;
	return (true);
}
