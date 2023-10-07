/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:29 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/07 14:39:34 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char **argv)
{
	(void)argc;

	//mlx_t* mlx = NULL;
	mlx_image_t* img = NULL;

	t_game_map *game;
	
	game = create_game_map(argv[1]);
	
	game->map = (char**)malloc(game->height * sizeof(char*));
	if (!game->map)
 		return (0);
	ft_check_file_ext(argv[1], ".ber");
	ft_map_to_arr(game);
	ft_is_map_close(game);
	ft_is_map_rect(game->width, game);
	ft_check_mando_char(game);
	ft_p_position(game);
	ft_arr_cpy(game);
	ft_is_path_valid(game);


	game->mlx = mlx_init((game->width *64), (game->height *64), "SO_LONG", true);
	if(!game->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	ft_arr_texture(game);
	ft_texture_to_image(game);
	ft_load_png(game);
	// ft_player_moves(game);
	printf("player position x : %d", game->player_x);
	printf("player position y : %d", game->player_y);
	printf("avant mlx_loop\n");

	printf("avant keyhook\n");
	mlx_loop_hook(game->mlx, ft_load_png, game);
	mlx_key_hook(game->mlx, &ft_player_moves, game);
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, img);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}

