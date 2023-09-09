/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:29 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/09 01:26:52 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_map *g_game_map;

void	ft_check_file_ext(char *map_file, char *req_ext)
{

	int n;
	int i;

	n = (ft_strlen(map_file) - 4);
	i = 0;

	if (!map_file || !req_ext)
		return;
	while(req_ext[i] != '\0' && map_file[n] != '\0')
	{
		if(req_ext[i] == map_file[n])
		{
			i++;
			n++;
		}
		else
			ft_exiting_prog(1, "wrong file extension...");
	}
	
}

void	ft_check_line_char(char *line, int indx, int player, int collectible, int way_out)
{
	indx = 0;
	player = 0;
	collectible = 0;
	way_out = 0;

	while(line[indx] != '\0')
	{
		if( line[indx] == '0' || line[indx] == '1' || line[indx] == 'C' || line[indx] == 'E' || line[indx] == 'P' || line[indx] == '\n')
		{
			if(line[indx] == 'C')
				collectible++;
			if(line[indx] == 'P')
				player++;
			if(line[indx] == 'E')
				way_out++;
		indx++;
		}
		else
		{
			printf("error here : %d\n", indx);
			ft_exiting_prog(1, "invalid character..error\n");
		}
	}
	if(player > 1 || way_out > 1)
	{
		printf("line : %s\n", line);
		ft_exiting_prog(1, "too many players or exits on the map\n");
	}
}

int		ft_count_line(char *file_path)
{
	int read_byte;
	char c;
	int line_num;

	line_num = 1;
	read_byte = 1;
	int fd = open(file_path, O_RDONLY);
	while(1)
	{
		read_byte = read(fd, &c, 1);
		if(read_byte <= 0)
			break;
		if( c == '\n')
			line_num++;
	}
	close(fd);
	return(line_num);
}

int	main(int argc, char **argv)
{
	int i; 
	i = -1;
	
	g_game_map = create_game_map(argv[1]);
	g_game_map->height = ft_count_line(argv[1]);

	printf("height of the array : %d\n", g_game_map->height);
	g_game_map->map = (char**)malloc(g_game_map->height * sizeof(char*));
	if (!g_game_map->map)
 		return (0);
	ft_check_file_ext(argv[1], ".ber");
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("error...non-existant or empty file\n");
		exit(0);
	}
	else
		printf("file openned\n");
	while(++i < g_game_map->height)
	{
		g_game_map->map[i] = get_next_line(fd);
		ft_check_line_char(*g_game_map->map, g_game_map->indx, g_game_map->player, g_game_map->collect, g_game_map->way_out);
		printf("first line of file : %s\n", g_game_map->map[i]);
	}
	return(0);
}