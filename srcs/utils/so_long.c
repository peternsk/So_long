/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:29 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/12 17:24:06 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char **argv)
{
	t_game_map	*game;

	if (argc == 2)
	{
		game = create_game_map(argv[1]);
	
		if(first_rnd_pars(game, argv[1]) != true)
			return(EXIT_FAILURE);
		ft_p_position(game);
		ft_ext_position(game);
		ft_arr_cpy(game);
		ft_is_path_valid(game);

		ft_init(game);
	}
	else
	{
		ft_ext_prg("too many or missing argument(s)\n");
		return(EXIT_FAILURE);
	}
}
