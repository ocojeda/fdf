/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:32:26 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/20 10:17:16 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned int	ft_ischar(char c, int power, unsigned int i)
{
	if (ft_isalpha(c))
	{
		if ((c >= 65) && (c <= 90))
			i = i + ((c - 'A' + 10) * pow(16, power));
		else
			i = i + ((c - 'a' + 10) * pow(16, power));
	}
	else
		i = i + (c - '0') * pow(16, power);
	return (i);
}

unsigned int	ft_atoi_hexa(char *nbr)
{
	unsigned int	i;
	char			*str;
	char			str2[3];
	int				power;
	int				e;

	i = 0;
	if (!nbr)
		return (0);
	str = ft_strchr(nbr, 'x') + 1;
	power = ft_strlen(str) - 1;
	while (*str)
	{
		ft_strncpy(str2, str, 2);
		e = 0;
		while (str2[e])
		{
			i = ft_ischar(str2[e], power--, i);
			e++;
		}
		str += 2;
	}
	return (i);
}
