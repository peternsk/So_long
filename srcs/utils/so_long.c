/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:29 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/13 23:10:44 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char **argv)
{
	t_game_map	*game;

	if (argc == 2)
	{
		game = create_game_map(argv[1]);
		if (first_rnd_pars(game, argv[1]) == false)
			return (EXIT_FAILURE);
		if (second_rnd_pars(game) == false)
			return (EXIT_FAILURE);
		ft_init(game);
	}
	else
	{
		ft_ext_prg("too many or missing argument(s)\n");
		return (EXIT_FAILURE);
	}
}
