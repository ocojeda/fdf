/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:12:44 by myernaux          #+#    #+#             */
/*   Updated: 2017/02/20 16:49:42 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int			ft_maplong(t_point *fp)
  {
  t_point		*temp;
  int			i;

  i = 0;
  temp = fp;
  while (temp)
  {
  i++;
  temp = temp->nextx;
  }
  return (i);
  }*/

/*int			ft_maphigh(t_point *fp)
  {
  t_point		*temp;
  int			i;

  i = 0;
  temp = fp;
  while (temp)
  {
  i++;
  temp = temp->nexty;
  }
  return (i);
  }*/

/*int			ft_maplength(t_point *fp)
  {
  t_point		*temp;
  int			i;

  i = 0;
  temp = fp;
  while (temp)
  {
  i++;
  temp = temp->nextx;
  }
  return (i);
  }*/

t_point		*ft_find_centermap(t_point *fp)
{
	t_point		*temp;
	t_point		*temp2;
	float		x;
	float		x1;
	float		y;
	float		y1;

	x = fp->x;
	x1 = fp->x;
	y1 = fp->y;
	y1 = fp->y;
	temp = fp;
	while (temp)
	{
		temp2 = temp;
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
		temp = temp->nexty;
	}
	x = (x1 - x) / 2 + x;
	y = (y1 - y) / 2 + y;
	return (new_point(x, y, 0, 0));
}

void		ft_center_norme(int i, int higth, t_point *fp, t_point *center)
{
	i = center->y - higth / 2;
	while (i--)
		test(fp, ft_moveup);
}

void		ft_center(t_point *fp, t_point *center, int length, int higth)
{
	int i;

//	while(center->nextx)
//		center = center->nextx;
//	while(center->nexty)
//		center = center->nexty;
//	center = ft_find_centermap(fp);
	if (center->x < length / 2)
	{
		i = length / 2 - center->x;
		while (i--)
			test(fp, ft_mover);
	}
	if (center->x > length / 2)
	{
		i = center->x - length / 2;
		while (i--)
			test(fp, ft_movel);
	}
	if (center->y < higth / 2)
	{
		i = higth / 2 - center->y;
		while (i--)
			test(fp, ft_movedown);
	}
	if (center->y > higth / 2)
		ft_center_norme(i, higth, fp, center);
	ft_putendl("hijoputa");
}
