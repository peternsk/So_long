/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:49 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/08 12:28:13 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h" 

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
