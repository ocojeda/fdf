/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 08:57:35 by myernaux          #+#    #+#             */
/*   Updated: 2017/03/03 14:12:54 by myernaux         ###   ########.fr       */
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

void	ft_isvalid(char **str)
{
	int i;
	int j;
	int a;
	int b;

	i = -1;
	j = -1;
	a = 0;
	b = 0;
	while (str[++i][++j] != '\0')
	{
		if ((str[i][j] >= '0' && str[i][j] <= '9') || (str[i][j] == 'x' || str[i][j] == ','))
			return ;
		else
			ft_error("Invalid File 3");
	}
}
