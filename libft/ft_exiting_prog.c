/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exiting_prog.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:06:38 by peternsaka        #+#    #+#             */
/*   Updated: 2023/08/29 14:22:54 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_exiting_prog(int out, char *mess_out)
{
	printf("%s", mess_out);
	exit(out);
}
