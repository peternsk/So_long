/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:29 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/09 16:27:11 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char **argv)
{
	//mlx_image_t *img;
	t_game_map *game;

	(void)argc;
	//img = NULL;
	game = create_game_map(argv[1]);
	game->map = (char **)malloc(game->height * sizeof(char *));
	if (!game->map)
		return (0);
	ft_check_file_ext(argv[1], ".ber");
	ft_map_to_arr(game);
	ft_is_map_close(game);
	ft_is_map_rect(game->width, game);
	ft_check_mando_char(game);
	ft_p_position(game);
	ft_ext_position(game);
	ft_arr_cpy(game);
	ft_is_path_valid(game);

	ft_init(game);
}