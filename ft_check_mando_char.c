/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_mando_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:07:13 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/11 21:59:38 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	this function will verify if the map have all the mendotory characters
		==> " 0 1 P C E"
	fot that ill use a homemade boolean function. 
	ive already stuck my mendo char by incrementing them in my struct when i was 
	ittereting. to make it easier all just vetifie with my struc and depending of the char
	missing ill display a certain type of error.

	==> P
		if no players -> missing player
		if too many players -> to many players in game
		if number of player == 1 -> return a boolean value equal to continue
	
	==> E
		if no exit -> missing exit
		if too many exit -> to many exits in game
		if number of exit == 1 -> return a boolean value equal to continue

	==> C
		if no collectible -> no collectible in game
		if collectible number > 0 -> return a boolean value equal to continue

		#####			#####			#####
		# P	#			# E	#			# C	#
		#####			#####			#####
*/

#include "so_long.h"

void		ft_check_mando_char(t_game_map *g_game_map)
{
	int num_of_player 	= g_game_map->player;
	int num_of_exit		= g_game_map->way_out;
	int num_of_collect 	= g_game_map->collect;

	if(num_of_player == 1 && num_of_exit == 1 && num_of_collect > 0)
		printf("all mando char are in map\n");
	else
		printf("missing mando char\n");
}