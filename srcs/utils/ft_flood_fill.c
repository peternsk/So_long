/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:08:55 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/18 10:13:21 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This function will output if there a valid path between my player and the exit.
	it will return either a valid path or an none valid path.

	COORDINATE :  							(x, y)
	STARTING POSITION						(0, 0)

				UP 		=> 	(x, y + 1)
				RIGHT 	=> 	(x + 1, y)
				DOWN 	=> 	(x, y - 1)
				LEFT 	=> 	(x - 1, y)
			
	==> I've to manage a way to keep track of the path ive taken.
	==> I can't go over :
							--> walls ('1')
							--> array limits (width, height)
	
	if the player incounter a wall ('1'), it will check if other directions are available 
	if all the options are unavailable, then the player backtrack to find a node with a remaining
	direction that can be use. 

	QUESTION ??? : 
					==> how do I keep the path taken so far ? ==> using the stack with recursive or malloc a queu with lenght and width of the array
					==> how do I save the choice taken by a node ?
	
	I'll need this function to traverse all the nodes of this graph so i can compare the number of 
	collectibles with them that ive reach using the flood fill algorith

							0123456789              ==>right              '#'	(Row, Collum)
						  0	1111111111				==>left					
						  1	1#01110C01				==>up
						  2	1##0000011				==>down
						  3	11100C0001
						  4	111E000011
						  5	1111111111


						STACK : 
								|			|
								|			|
								|			|
								|			|
								|			|
								|			|
								|			|
								|			|
								|			|
								|			|
								|			|
								|			|
								|			|
								|	(2,2)	|
								|	(2,3)	|
								|	(0,1)	|	==> Wall
								|	(1,0)	|	==> wall
								|	(1,2)	|
								 ___________
	Flood Fill param :  
						==> int x : will assign the position of rows
						==> int y : will assign the positionof collums
						==> char fill : will be the 
						==> char **map : the map that ill bw working with 
						==> int height : the 
						==> int width

	COORDINATE :  							(x, y)
	STARTING POSITION						(0, 0)

				UP 		=> 	(x, y + 1)
				RIGHT 	=> 	(x + 1, y)
				DOWN 	=> 	(x, y - 1)
				LEFT 	=> 	(x - 1, y)

	RETURN STATEMENT :
						==> the return statement return a value or a variable to the calling function
*/

#include "../so_long.h"


void    ft_flood_fill(int x, int y, t_game_map *game)
{
    if(game->maze[x][y] == '1' || game->maze[x][y] == '+')
        return;
    if(game->maze[x][y] == 'C')
        game->collect_flood++;
    if(game->maze[x][y] == 'E')
        game->exit_flood++;
    game->maze[x][y] = game->fill;
    ft_flood_fill(x, y + 1, game);
    ft_flood_fill(x, y - 1, game);
    ft_flood_fill(x + 1, y, game);
    ft_flood_fill(x - 1, y, game);
}

