/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:24:56 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/05 12:33:57 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	this function verify if my map is close. that means that there's 1s all arround
	the map.

	rep :
			111111111111111
			1             1
			1             1
			1             1
			1             1
			1             1
			1             1
			1             1
			111111111111111

		my strategie will be:
							=> loop throgh my first line to verify that they are all 1s
							=> make a comparation with my last line
							=> itterate in the lines in between to make sure that they are all start 
								and ends with 1s.

*/

#include "so_long.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>


// void	ft_close_map(char **map, int height, int length)
// {
// 	int row_indx = 0;
// 	int collum_indx = 0;

// 	while(row_indx < 1)
// 	{
// 		if(map[collum_indx] == '1')
// 			collum_indx++;
// 		else
// 			printf("open map...can't play\n");
// 	}

// }

int main(void)
{
	#define height 6
	#define length 5

	int map[height][length] = { {1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1} };
	
	int row = 0;
	int collum = 0;

	while (collum < height)
	{
    	if (map[0][collum] == '1')
		{
        	printf("Found an 'x' in the first row at column : %d\n", collum);
    	}
    collum++;
	}
}
