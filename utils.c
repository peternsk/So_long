/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:20:28 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/08 15:26:27 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_line_char(char *line)
{
	int indx = 0;
	int Player = 0;
	int collectible = 0;
	int	way_out = 0;

	while(line[indx] != '\n')
	{
		if( line[indx] == '0' || line[indx] == '1' || line[indx] == 'C' || line[indx] == 	'E' || line[indx] == 'P'){
			if(line[indx] == 'C')
				collectible++;
			if(line[indx] == 'P')
				Player++;
			if(line[indx] == 'E')
				way_out++;
		indx++;
		}
		if(Player > 1)
		{
			printf("line : %s\n", line);
			ft_exiting_prog(1, "too many players for the game\n");
		}
		if(way_out > 1)
		{
			printf("line : %s\n", line);
			ft_exiting_prog(1, "too many exits for the game\n");
		}
		//ft_exiting_prog(1, "not a valid char\n");
	}
	printf("lenght : %d\n", indx);
	printf("player : %d\n", Player);
	printf("collectible : %d\n", collectible);
	printf("way_out : %d\n", way_out);

}


void		ft_check_file_ext(char *map_file, char *req_ext)
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