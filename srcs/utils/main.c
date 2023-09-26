/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:29 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/26 10:36:53 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	(void)argc;

	mlx_t* mlx;
	mlx_image_t* img = NULL;

	t_game_map *g_game_map;
	t_flood_maze *g_maze;
	t_image_maze *image_maze;
	
	g_game_map = create_game_map(argv[1]);
	g_maze = create_flood_maze(g_game_map);
	image_maze = create_image_maze();
	
	g_game_map->map = (char**)malloc(g_game_map->height * sizeof(char*));
	if (!g_game_map->map)
 		return (0);
	ft_check_file_ext(argv[1], ".ber");
	ft_map_to_arr(g_game_map);
	ft_is_map_close(g_game_map);
	ft_is_map_rect(g_game_map->width, g_game_map);
	ft_check_mando_char(g_game_map);
	ft_p_position(g_game_map, g_maze);
	ft_arr_cpy(g_game_map, g_maze);
	ft_is_path_valid(g_game_map, g_maze);
	
	mlx = mlx_init((g_game_map->width *64), (g_game_map->height *64), "SO_LONG", true);
	if(!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	ft_arr_texture(image_maze);
	ft_texture_to_image(image_maze, img, mlx);
	ft_load_png(mlx, g_game_map, image_maze);

	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}