/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:21:42 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/08 23:53:11 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_game_map
{
	char	**map;
	int		collect;
	int		player;
	int		way_out;
	int		height;
	int		lenght;
	int		indx;
	
}			t_game_map;

t_game_map	*create_game_map(char *file_path)
{
	t_game_map	*game_map;

	game_map = malloc(1 * sizeof(t_game_map));
	if (!game_map)
		return (NULL);
	game_map->map = 0;
	game_map->collect = 0;
	game_map->player = 0;
	game_map->way_out = 0;
	game_map->height = 0;
	game_map->lenght = 0;
	game_map->indx = 0;
	return (game_map);
}

t_game_map	*create_game_map(char *file_path);
void		ft_check_line_char(char *line, int indx, int player, int collectible, int way_out);
void		ft_check_file_ext(char *map_file, char *req_ext);
int			ft_count_line(char *file_path);

#endif