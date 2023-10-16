/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:29 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 15:57:36 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char **argv)
{
	t_game_map	*game;

	if (argc == 2)
	{
		int	fd;
		
		fd = open(argv[1], O_RDONLY);
		if (fd == -1 || fd == 0)
			return (EXIT_FAILURE);
		printf("fd: %d\n", fd); 
		game = create_game_map(argv[1]);
		if (first_rnd_pars(game, argv[1], fd) == false)
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
