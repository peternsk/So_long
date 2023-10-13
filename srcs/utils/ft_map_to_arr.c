/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:58:27 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/13 16:05:03 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	ft_map_to_arr(t_game_map *game, char *file_path)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_ext_prg("error...non-existant or empty file\n");
	game->map = (char **)ft_calloc(game->height + 1, sizeof(char *));
	if (!game->map)
		ft_ext_prg("memory allocation issue\n");
	while (++i < game->height)
	{
		game->map[i] = get_next_line(fd);
		ft_check_line_char(game->map[i], game);
	}
	game->map[i] = NULL;
	close(fd);
	return (true);
}
