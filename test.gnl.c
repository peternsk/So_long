/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:29 by peternsaka        #+#    #+#             */
/*   Updated: 2023/09/07 10:26:33 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_strlen_GNL(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 	{
// 		return (0);
// 	}
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_str_attach_GNL(char *base_str, char *add_str)
// {
// 	char	*new_str;
// 	int		len;

// 	len = (ft_strlen_GNL(base_str) + ft_strlen_GNL(add_str));
// 	new_str = (char *)malloc(len * sizeof(char) + 1);
// 	if (!new_str)
// 		return (0);
// 	len = 0;
// 	if (base_str != NULL)
// 	{
// 		while (base_str[len])
// 		{
// 			new_str[len] = base_str[len];
// 			len++;
// 		}
// 		free(base_str);
// 	}
// 	while (*add_str)
// 	{
// 		new_str[len] = *add_str;
// 		len++;
// 		add_str++;
// 	}
// 	new_str[len] = '\0';
// 	return (new_str);
// }

// char	*ft_memcpy_GNL(char *dst, const char *src, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!dst && !src)
// 		return (0);
// 	while (i < n)
// 	{
// 		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
// 		i++;
// 	}
// 	return (dst);
// }

// char	*ft_memmove_GNL(char *dst, char *src, size_t len)
// {
// 	len = ft_strlen_GNL(src);
// 	if (!dst || !src)
// 		return (0);
// 	if (dst == NULL && src == NULL)
// 		return (NULL);
// 	if (dst >= src)
// 	{
// 		while (len > 0)
// 		{
// 			dst[len - 1] = src[len - 1];
// 			len--;
// 		}
// 	}
// 	else
// 	{
// 		ft_memcpy_GNL(dst, src, len);
// 	}
// 	dst[ft_strlen_GNL(src)] = '\0';
// 	return (dst);
// }


// char	*ft_new_line_GNL(char *str)
// {
// 	char	*str_wobakn;
// 	int		i;

// 	i = 0;
// 	str_wobakn = malloc(sizeof(char) + ft_strlen_GNL(str) + 1);
// 	while (str[i])
// 	{
// 		str_wobakn[i] = str[i];
// 		if (str[i] == '\n')
// 		{
// 			i++;
// 			break ;
// 		}
// 		i++;
// 	}
// 	str_wobakn[i] = '\0';
// 	str = ft_memmove_GNL(str, str + i, ft_strlen_GNL(str + i));
// 	return (str_wobakn);
// }


// size_t	ft_chr_bakn_GNL(char *str, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*str_stat;
// 	char		buffer[BUFFER_SIZE + 1];
// 	ssize_t		read_char;

// 	read_char = read(fd, buffer, BUFFER_SIZE);
// 	while (read_char > 0)
// 	{
// 		buffer[read_char] = '\0';
// 		str_stat = ft_str_attach_GNL(str_stat, buffer);
// 		if (ft_chr_bakn_GNL(buffer, '\n') == 1)
// 			break ;
// 		read_char = read(fd, buffer, BUFFER_SIZE);
// 	}
// 	if ((read_char == -1) || (read_char <= 0 && ft_strlen_GNL(str_stat) == 0))
// 	{
// 		if (str_stat)
// 		{
// 			free(str_stat);
// 			str_stat = NULL;
// 		}
// 		return (NULL);
// 	}
// 	return (ft_new_line_GNL(str_stat));
// }

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

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	i = -1;
// 	while (s[++i])
// 		;
// 	return (i);
// }

// void    ft_exiting_prog(int out, char *mess_out)
// {
// 	printf("%s", mess_out);
// 	exit(out);
// }

void	ft_check_line_char(char *line)
{
	int indx = 0;
	int Player = 0;
	int collectible = 0;
	int	way_out = 0;

	while(line[indx] != '\n')
	{
		if( line[indx] == '0' || line[indx] == '1' || line[indx] == 'C' || line[indx] == 	'E' || line[indx] == 'P'){
			if(line[indx] == 'C')
				collectible++;
			if(line[indx] == 'P')
				Player++;
			if(line[indx] == 'E')
				way_out++;
		indx++;
		}
		if(Player > 1)
		{
			printf("line : %s\n", line);
			ft_exiting_prog(1, "too many players for the game\n");
		}
		if(way_out > 1)
		{
			printf("line : %s\n", line);
			ft_exiting_prog(1, "too many exits for the game\n");
		}
		//ft_exiting_prog(1, "not a valid char\n");
	}
	printf("lenght : %d\n", indx);
	printf("player : %d\n", Player);
	printf("collectible : %d\n", collectible);
	printf("way_out : %d\n", way_out);

}

int	main(int argc, char **argv)
{
	char *gnl_output;
	test__ft_check_file_ext(argv[1], ".ber");
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("error...non-existant or empty file\n");
		exit(0);
	}
	else
		printf("file openned\n");
	gnl_output = get_next_line(fd);
	ft_check_line_char(gnl_output);
	//printf("first line of file : %s\n", gnl_output);
	return(0);
}