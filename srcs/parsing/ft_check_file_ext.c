/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:21 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 13:10:53 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	ft_check_file_ext(char *map_file, char *req_ext)
{
	int	n;
	int	i;

	n = (ft_strlen(map_file) - 4);
	i = 0;
	if (!map_file || !req_ext)
		return (false);
	while (req_ext[i] != '\0' && map_file[n] != '\0')
	{
		if (req_ext[i] == map_file[n])
		{
			i++;
			n++;
		}
		else
			return (false);
	}
	return (true);
}
