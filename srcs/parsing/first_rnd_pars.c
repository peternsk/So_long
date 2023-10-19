/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_rnd_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:02:58 by pnsaka            #+#    #+#             */
/*   Updated: 2023/10/18 19:51:43 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	first_rnd_pars(t_game_map *game, char *arg, int fd)
{
	if (ft_check_file_ext(arg, ".ber") == false)
		ft_free_f(game, "wrong file extention");
	if (ft_map_to_arr(game, arg, fd) == false)
		ft_free_f(game, "map allocation error or empty file");
	if (ft_check_line_char(game) == false)
		ft_free_f(game, "char error");
	if (ft_map_limits(game) == false)
		ft_free_f(game, "map too big to enjoy the game 😞");
	if (ft_is_map_close(game) == false)
		ft_free_f(game, "open map");
	if (ft_is_map_rect(game->width, game) == false)
		ft_free_f(game, "map is not rectangle");
	if (ft_check_mando_char(game) == false)
		ft_free_f(game, "missing or unknown char in map");
	return (true);
}
