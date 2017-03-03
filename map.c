/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:12:44 by myernaux          #+#    #+#             */
/*   Updated: 2017/03/02 11:33:44 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_maphight(t_point *fp)
{
	t_point		*temp;

	temp = fp;
	while (temp->nexty)
	{
		temp = temp->nexty;
	}
	return (temp->y - fp->y);
}

int			ft_maplength(t_point *fp)
{
	t_point		*temp;

	temp = fp;
	while (temp->nextx)
	{
		temp = temp->nextx;
	}
	return (temp->x - fp->x);
}

t_point		*ft_find_centermap(t_point *fp, float x, float x1, float y)
{
	t_point		*temp2;
	float		y1;

	y1 = fp->y;
	while (fp)
	{
		temp2 = fp;
		while (temp2)
		{
			if (temp2->x < x)
				x = temp2->x;
			if (temp2->x > x1)
				x1 = temp2->x;
			if (temp2->y < y)
				y = temp2->y;
			if (temp2->y > y1)
				y1 = temp2->y;
			temp2 = temp2->nextx;
		}
		fp = fp->nexty;
	}
	x = (x1 - x) / 2 + x;
	y = (y1 - y) / 2 + y;
	return (new_point(x, y, 0, 0));
}

void		ft_center(t_point *fp, t_point *center, int length, int higth)
{
	test3(fp, matrice_translate_rl, length / 2 - center->x);
	test3(fp, matrice_translate_ud, higth / 2 - center->y);
}
