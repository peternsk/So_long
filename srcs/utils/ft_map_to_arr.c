/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:58:27 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/10 13:26:31 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_map_to_arr(t_game_map *game)
{
	int	i;

	i = -1;
	if (game->fd == -1)
		ft_exiting_prog(1, "error...non-existant or empty file\n");
	while (++i < game->height)
	{
		game->map[i] = get_next_line(game->fd);
		ft_check_line_char(game->map[i], game->indx, game);
	}
}
