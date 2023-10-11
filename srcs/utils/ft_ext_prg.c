/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exiting_prog.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:06:38 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/11 15:27:53 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_ext_prg(t_game_map *game, int out, char *mess_out)
{
	printf("%s", mess_out);
	ft_free_f(game);
	exit(out);
}
