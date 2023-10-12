/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RENE_GNL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:12:09 by pnsaka            #+#    #+#             */
/*   Updated: 2023/10/12 13:23:52 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*RENE_ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	total;
	char	*ptr;

	i = 0;
	total = count * size;
	ptr = (void *)malloc(total);
	if (!ptr)
		return (NULL);
	while (i < total)
		ptr[i++] = 0;
	return ((void *)ptr);
}

static char	*RENE_ft_read_buff(char *stash, int fd)
{
	char	*buff;
	int		ret;

	buff = (char *)RENE_ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	ret = 1;
	while (!ft_strchr(stash, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[ret] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*RENE_get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = RENE_ft_read_buff(stash, fd);
	if (!stash)
		return (NULL);
	line = RENE_ft_get_line(stash);
	stash = RENE_ft_clean_stash(stash);
	return (line);
}
