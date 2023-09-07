/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_line_GNL.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:36:12 by peternsaka        #+#    #+#             */
/*   Updated: 2023/08/29 12:51:05 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new_line_GNL(char *str)
{
	char	*str_wobakn;
	int		i;

	i = 0;
	str_wobakn = malloc(sizeof(char) + ft_strlen_GNL(str) + 1);
	while (str[i])
	{
		str_wobakn[i] = str[i];
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	str_wobakn[i] = '\0';
	str = ft_memmove_GNL(str, str + i, ft_strlen_GNL(str + i));
	return (str_wobakn);
}
