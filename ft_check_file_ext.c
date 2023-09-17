/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:21 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/12 15:43:15 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"

/* the goal of this function is to compare the extention on the given file to the require 
   extention.
   
   to do so i'll compare the last 4 characters of the second argument to the a to 4 char string
   made off the last 4 char of the require extention.
   
   ex:
   		argv[1] = the map or file

		char *file_ext  = ".ber" (the require extention
		
		ft_strlen(argv[1]) = the width of the the second argument )
				ex : ./so_long source/map1.ber
				
				ft_strlen(argv[1])  = 15
		there for, i'll have to impliment a variable 'n' that will have the value of ft_strlen(argv[1] - 4)
		
		#######.....#######.....#######.....#######
		#.....#.....#.....#.....#.....#.....#.....#
		#.....#.....#.....#.....#.....#.....#.....#
		#######.....#######.....#######.....#######
           .           b           e           r
		
		 */



/*------------------------------------------------------------------------------------------------------*/

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

int main(void)
{
	char *map = "hello.bee";
	char *ext = ".ber";

	test__ft_check_file_ext(map, ext);

	return(0);
}
