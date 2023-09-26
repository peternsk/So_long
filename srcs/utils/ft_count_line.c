/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:49 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/18 09:48:16 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h" 
/*
	this function will help to count the number of line(row) in the file.
	to be more specific, it will count the number of '\n' in the file 

	rep : 
		map.ber ==>		
					1111111111\n
					1000000001\n
					1000000001\n
					1000000001\n
					1000000001\n
					1000000001\n
					1111111111\0
		
		this function will read the file and each time that it will encounter a 
		'\n' it will increment my counter. till the end of file.
*/

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
