/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_mando_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:07:13 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/07 14:38:09 by pnsaka           ###   ########.fr       */
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

#include "../../so_long.h"

void		ft_check_mando_char(t_game_map *game)
{
	int num_of_player 	= game->player;
	int num_of_exit		= game->way_out;
	int num_of_collect 	= game->collect;

	if(num_of_player == 1 && num_of_exit == 1 && num_of_collect > 0)
		printf("all mando char are in map\n");
	else
		ft_exiting_prog(1, "missing mando char\n");
}