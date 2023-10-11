/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:29 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/11 17:40:52 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_is_valid_input()
{
	
	
	return(1);
}

int	main(int argc, char **argv)
{
	t_game_map	*game;

	if (argc < 2)
		return(EXIT_FAILURE);
	else if (argc == 2)
	{
		game = create_game_map(argv[1]);
		
		game->map = (char **)malloc(game->height * sizeof(char *));
		if (!game->map)
			ft_exiting_prog(1, "memory allocation issue\n");
		printf("game address : %p\n", game->map);
		//parssing function round 1
		ft_map_to_arr(game, argv[1]);
		ft_check_file_ext(game, argv[1], ".ber");
		ft_is_map_close(game);
		ft_is_map_rect(game->width, game);
		ft_check_mando_char(game);
		
		ft_p_position(game);
		ft_ext_position(game);
		ft_arr_cpy(game);
		ft_is_path_valid(game);
		//if parssing function works = init mlx
		system("leaks executablename"); 
		ft_init(game);
	}
	else
		return(EXIT_FAILURE);
}
