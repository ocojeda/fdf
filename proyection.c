/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proyection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 19:16:44 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/18 14:39:35 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*ft_proyection(t_point *fp)
{
	int			x;
	t_point		*temp;
	t_point		*temp2;

	temp = fp;
	while (temp)
	{
		temp2 = temp;
		while (temp2)
		{
			x = temp2->x;
			temp2->x = temp2->x * cos(0.75) - temp2->y * sin(0.5);
			temp2->y = x * sin(0.5) + temp2->y * cos(0.75);
			temp2->x = temp2->z + (0.5 * temp2->x);
			temp2->y = temp2->y + ((0.5 / 2) * temp2->z);
			temp2 = temp2->nextx;
		}
		temp = temp->nexty;
	}
	return (fp);
}

void		ft_put_pix_map(t_point *fp, t_screen *fst, t_point *t, t_point *t2)
{
	t = fp;
	while (t)
	{
		t2 = t;
		while (t2)
		{
			ft_put_diagonal(t2, t2->nextx, fst);
			ft_put_diagonal(t2, t2->nexty, fst);
			t2 = t2->nextx;
		}
		t = t->nexty;
	}
}
