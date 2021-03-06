/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proyection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 19:16:44 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/27 12:00:24 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		*ft_proyection(t_point *fp)
{
	int			x;

	x = fp->x;
	fp->x = fp->x * cos(0.75) - fp->y * sin(0.5);
	fp->y = x * sin(0.5) + fp->y * cos(0.75);
	fp->x = fp->z + (0.5 * fp->x);
	fp->y = fp->y + ((0.5 / 2) * fp->z);
	return (0);
}

void		ft_put_pix(t_point *fp, t_screen *fst, t_point *t, t_point *t2)
{
	t = fp;
	while (t)
	{
		t2 = t;
		while (t2 && (t2->nextx != fst->center))
		{
			if (t2->nextx != NULL)
				ft_put_diagonal(t2, t2->nextx, fst);
			if (t2->nexty != NULL)
				ft_put_diagonal(t2, t2->nexty, fst);
			t2 = t2->nextx;
		}
		t = t->nexty;
	}
	t = fp;
	while (t->nextx)
		t = t->nextx;
	while (t->nexty->nexty)
		t = t->nexty;
	if (t->nexty && t)
		ft_put_diagonal(t->nexty, t, fst);
}
