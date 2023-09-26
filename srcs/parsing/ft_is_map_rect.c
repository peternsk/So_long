/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:49:00 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/18 09:48:16 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	this function will determine if the map is rectangle.
	here the geometric definition definition of of a rectangle :

		Rectangle is a closed polygon with four sides i.e., a quadrilateral 
		in which all four angles are equal and the measure of each angle
		is 90 degrees and the opposite side of the quadrilateral is parallel
		and equal. Any quadrilateral that follows the given criteria can be 
		considered a Rectangle, thus a square can be considered a rectangle but 
		the opposite is not the same, i.e. a rectangle is not a square. 

	MAP :
			############         	#############             	#				#####
			############			############				##				####
			############			##########					###				######
			############			#########					####			#####
			############			########					#####			####
			############			###########					######			###

	with this descriptoin, i'll have to come with this description for this function.
		==> all row must be of the same width.
*/

#include "../so_long.h"

void	ft_is_map_rect(int width, t_game_map *g_game_map )
{
	int i = 0;
	width = ft_strlen(g_game_map->map[i]) - 1;

	while( i < g_game_map->height)
	{
		if(g_game_map->width == width)
			i++;
		else
			ft_exiting_prog(1, "map not rectangle\n");
	}
	printf("map is rectangle\n");
}