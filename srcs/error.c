/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:09:09 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/26 12:09:12 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(char *str, int fd)
{
	if (fd)
		close(fd);
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

void	ft_file(char *str)
{
	int		len;
	int		i;
	char	s1[4];

	i = 0;
	len = ft_strlen(str);
	len -= 4;
	while (i != 4)
		s1[i++] = str[len++];
	s1[i] = '\0';
	if (ft_strcmp(s1, ".fdf") != 0)
		ft_error("Only .fdf file\n", 0);
}
