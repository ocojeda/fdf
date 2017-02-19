/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proyection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 19:16:44 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/19 15:15:58 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		*ft_proyection(t_point *fp)
{
	int			x;
	x = fp->x;
	fp->x = fp->x * cos(0.75) - fp->y * sin(0.5);
	fp->y = x * sin(0.5) + fp->y * cos(0.75);
	fp->x = fp->z + (0.5 * fp->x);
	fp->y = fp->y + ((0.5 / 2) * fp->z);
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
