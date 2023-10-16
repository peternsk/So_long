/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_rnd_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:02:58 by pnsaka            #+#    #+#             */
/*   Updated: 2023/10/16 16:30:07 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	first_rnd_pars(t_game_map *game, char *arg, int fd)
{
	int i;
	
	i = 0;
	if (ft_check_file_ext(arg, ".ber") == false)
		ft_free_f(game, "wrong file extention");
	if (ft_map_to_arr(game, arg, fd) == false)
		ft_free_f(game, "unable to load the map");
	if (ft_check_line_char(game) == false)
		ft_free_f(game, "char error");
	if (ft_is_map_close(game) == false)
		ft_free_f(game, "open map");
	if (ft_is_map_rect(game->width, game) == false)
		ft_free_f(game, "map is not rectangle");
	if (ft_check_mando_char(game) == false)
		ft_free_f(game, "missing or unknown char in map");
	return (true);
}