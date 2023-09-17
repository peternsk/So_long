/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_path_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:08:55 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/17 11:43:02 by peternsaka       ###   ########.fr       */
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

#include "so_long.h"

void	ft_is_path_valid(int x, int y, char **map,char fill, int height, int width, t_flood_maze *maze)
{
	maze->maze_char = maze->maze[maze->x][maze->y];

	//out of bound
	if(maze->x < 0 || maze->x > maze->height || maze->y < 0 || maze->y > maze->width)
		return;
	//Wall in game of already visited node
	if(maze->maze_char == '1' || maze->maze_char == '#');
		return;
	//fill node & counting collectibles
	if(maze->maze_char == '0' || maze->maze_char == 'C' || maze->maze_char == 'P' || maze->maze_char == 'E')
	{
		if(maze->maze_char == 'C')
			maze->collect++;
		if(maze->maze_char == 'E')
			maze->exit++;
	}
	maze->maze_char = maze->fill;
	ft_is_path_valid(maze->x, maze->y + 1, maze->maze, maze->fill, maze->height, maze->width, maze);
	ft_is_path_valid(maze->x, maze->y - 1, maze->maze, maze->fill, maze->height, maze->width, maze);
	ft_is_path_valid(maze->x + 1, maze->y, maze->maze, maze->fill, maze->height, maze->width, maze);
	ft_is_path_valid(maze->x - 1, maze->y, maze->maze, maze->fill, maze->height, maze->width, maze);
}

