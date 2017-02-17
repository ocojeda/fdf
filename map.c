/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:12:44 by myernaux          #+#    #+#             */
/*   Updated: 2017/02/17 16:27:55 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

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
	t_point 	*temp;
	float		x;
	float		y;
	int			dec;

	x = fp->x;
	y = fp->y;
	temp = fp;
	while (temp->nextx)
		temp = temp->nextx;
	x = (temp->x - x) / 2 + x;
	temp = fp;
	while (temp->nexty)
		temp=temp->nexty;
	y = (temp->y -y) / 2 + y;
	return (new_point(x, y, 0, 0));
}

void		ft_center(t_point *fp, int length, int hight)
{
	int			i;
	t_point		*center;

	center = ft_find_centermap(fp);
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
	if (center->y < hight / 2)
	{
		i = hight / 2 - center->y;
		while (i--)
			test(fp, ft_movedown);
	}
	if (center->y > length / 2)
	{
		i = center->y - length / 2;
		while (i--)
			test(fp, ft_moveup);
	}
	free(center);
}
