/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:01:34 by pnsaka            #+#    #+#             */
/*   Updated: 2023/10/11 11:51:05 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_free_2d_map(char **map)
{
	int i;

	i = 0;

	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}


int    ft_free_s(t_game_map * game)
{
	ft_free_2d_map(game->map);
	ft_free_2d_map(game->maze);
	if(game->mlx)
	{
		mlx_delete_image(game->mlx, img);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	exit(EXIT_SUCCESS);
	return(EXIT_SUCCESS);
}

void    ft_free_f(t_game_map * game)
{
	if(game->map)
		free(s_game_map);
	if(game->maze)
		free(s_game_maze);
	if(game->mlx)
	{
		mlx_delete_image(game->mlx, img);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	exit (EXIT_FAILURE);
}