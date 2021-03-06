/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:40:30 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/03/03 14:57:24 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_map_count(t_point *fp)
{
	t_point	*temp;
	int		i;

	i = 0;
	temp = fp;
	while (temp->nextx)
	{
		temp = temp->nextx;
		i++;
	}
	return (i);
}

void		reset_map(t_point *temp)
{
	while (temp->nexty)
		temp = temp->nexty;
	while (temp->nextx)
		temp = temp->nextx;
	temp->y /= 2;
	temp->x /= 2;
}

void		ft_resetmap(t_point *fp, float *z0)
{
	int		x;
	int		y;
	int		c;
	t_point	*temp;
	t_point	*temp2;

	y = 0;
	c = ft_map_count(fp);
	temp = fp;
	while (temp)
	{
		x = 0;
		temp2 = temp;
		while (temp2)
		{
			temp2->x = x;
			temp2->y = y;
			temp2->z = z0[x + y * c];
			temp2 = temp2->nextx;
			x++;
		}
		y++;
		temp = temp->nexty;
	}
	reset_map(fp);
}

int			count_map(t_point *fp)
{
	t_point		*temp;
	t_point		*temp2;
	int			x;

	x = 0;
	temp = fp;
	while (temp)
	{
		temp2 = temp;
		while (temp2)
		{
			temp2 = temp2->nextx;
			x++;
		}
		x--;
		temp = temp->nexty;
	}
	return (x);
}

float		*ft_mapcpy(t_point *fp)
{
	t_point		*temp;
	t_point		*temp2;
	int			x;
	float		*z;

	temp = fp;
	x = count_map(fp);
	z = (float *)ft_memalloc(sizeof(float) * (x + 1));
	z[x + 1] = '\0';
	temp = fp;
	x = 0;
	while (temp)
	{
		temp2 = temp;
		while (temp2)
		{
			z[x++] = temp2->z;
			temp2 = temp2->nextx;
		}
		x--;
		temp = temp->nexty;
	}
	return (z);
}
