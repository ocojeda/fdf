/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 08:57:35 by myernaux          #+#    #+#             */
/*   Updated: 2017/03/02 12:24:56 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str)
{
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
		ft_error("Only .fdf file");
}
