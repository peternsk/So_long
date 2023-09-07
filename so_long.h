/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:21:42 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/07 10:36:21 by peternsaka       ###   ########.fr       */
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
	
}			t_game_map;

t_game_map	*create_game_map(char **map)
{
	t_game_map	*game_map;

	game_map = malloc(1 * sizeof(t_game_map));
	if (!game_map)
		return (NULL);
	game_map->map = map;
	game_map->collect = 0;
	game_map->player = 0;
	game_map->way_out = 0;
	game_map->height = 0;
	game_map->lenght = 0;
	return (game_map);
}

void	ft_check_line_char(char *line);
void		test__ft_check_file_ext(char *map_file, char *req_ext);


#endif