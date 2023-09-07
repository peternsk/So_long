/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:26:54 by peternsaka        #+#    #+#             */
/*   Updated: 2023/08/30 12:56:51 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "so_long.h"

t_game_map *g_game_map;

void    ft_exiting_prog(int out, char *mess_out)
{
	printf("%s", mess_out);
	exit(out);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		;
	return (i);
}

void		test__ft_check_file_ext(char *map_file, char *req_ext)
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

int		main(int argc, char **argv)
{
	
	if(argc != 2)
		ft_exiting_prog(1, "argument count issue...");
	test__ft_check_file_ext(argv[2], ".ber");
	
}