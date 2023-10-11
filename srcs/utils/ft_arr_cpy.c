/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:54:25 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/11 17:22:32 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// void	ft_arr_cpy(t_game_map *game, char *file_path)
// {
// 	int	i;
// 	int fd;

// 	i = 0;
// 	fd = open(file_path, O_RDONLY);
// 	game->maze = (char **)malloc(game->height * sizeof(char *));
// 	if (!game->maze)
// 	if (fd < 0)
// 		ft_ext_prg(game, 1, "error...non-existant or empty file\n");
// 	while (++i < game->height)
// 	{
// 		game->maze[i] = get_next_line(fd);
// 		ft_check_line_char(game->map[i], game->indx, game);
// 	}
// 	close(fd);
// 	ft_free_2d_map(game->maze);
// }

// void	ft_map_to_arr(t_game_map *game, char *file_path)
// {
// 	int	i;
// 	int	fd;

// 	i = -1;
// 	fd = open(file_path, O_RDONLY);
// 	if (fd < 0)
// 		ft_ext_prg(game, 1, "error...non-existant or empty file\n");
// 	game->map = (char **)malloc(game->height * sizeof(char *));
// 	if (!game->map)
// 		ft_ext_prg(game, 1, "memory allocation issue\n");
// 	while (++i < game->height)
// 	{
// 		game->map[i] = get_next_line(fd);
// 		ft_check_line_char(game->map[i], game->indx, game);
// 	}
// 	free(game->map);
// 	close(fd);
// }

void	ft_arr_cpy(t_game_map *game)
{
	int	i;

	i = 0;
	game->maze = (char **)malloc(game->height * sizeof(char *));
	if (!game->maze)
		ft_free_f(game);
	while (i < game->height)
	{
		game->maze[i] = ft_strdup(game->map[i]);
		i++;
	}
	//ft_free_2d_map(game->maze);
}

// void	ft_map_to_arr(t_game_map *game, char *file_path)
// {
// 	int	i;
// 	int	fd;

// 	i = -1;
// 	fd = open(file_path, O_RDONLY);
// 	if (fd < 0)
// 		ft_ext_prg(game, 1, "error...non-existant or empty file\n");
// 	game->map = (char **)malloc(game->height * sizeof(char *));
// 	if (!game->map)
// 		ft_ext_prg(game, 1, "memory allocation issue\n");
// 	while (++i < game->height)
// 	{
// 		game->map[i] = get_next_line(fd);
// 		ft_check_line_char(game->map[i], game->indx, game);
// 	}
// 	free(game->map);
// 	close(fd);
// }