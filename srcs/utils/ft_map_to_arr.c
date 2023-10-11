/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:58:27 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/11 17:22:12 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
void	ft_map_to_arr(t_game_map *game, char *file_path)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_ext_prg(game, 1, "error...non-existant or empty file\n");
	game->map = (char **)malloc(game->height * sizeof(char *));
	if (!game->map)
		ft_ext_prg(game, 1, "memory allocation issue\n");
	while (++i < game->height)
	{
		game->map[i] = get_next_line(fd);
		ft_check_line_char(game->map[i], game->indx, game);
	}
	//ft_free_2d_map(game->map);
	close(fd);
}
