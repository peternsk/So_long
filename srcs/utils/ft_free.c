/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:01:34 by pnsaka            #+#    #+#             */
/*   Updated: 2023/10/11 17:36:11 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_free_2d_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_game(t_game_map *game)
{
	if (!game)
		return ;
	while (game)
	{
		if (game != NULL)
			free(game);
		game++;
	}
	free(game);
}

void	ft_delete_image(t_game_map *game)
{
	int	i;

	i = 0;
	while (i < NUM_OF_IMAGE)
	{
		mlx_delete_image(game->mlx, game->arr_img[i]);
		i++;
	}
}

void	ft_delete_texture(t_game_map *game)
{
	int	i;

	i = 0;
	while (i < NUM_OF_IMAGE)
	{
		mlx_delete_texture(game->arr_txtur[i]);
		i++;
	}
}

int	ft_free_s(t_game_map *game)
{
	ft_free_2d_map(game->map);
	ft_free_2d_map(game->maze);
	if (game->mlx)
	{
		if (sizeof(game->arr_img) < 0)
			ft_delete_image(game);
		if (sizeof(game->arr_txtur) < 0)
			ft_delete_texture(game);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	free(game);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	ft_free_f(t_game_map *game)
{
	if (game->map)
		free(game->map);
	if (game->maze)
		free(game->maze);
	if (game->mlx)
	{
		if (sizeof(game->arr_img) < 0)
			ft_delete_image(game);
		if (sizeof(game->arr_txtur) < 0)
			ft_delete_texture(game);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	free(game->mlx);
	free(game);
	exit(EXIT_FAILURE);
}