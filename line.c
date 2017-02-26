/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:58:06 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/26 15:40:22 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_setpoint(t_point *pa, t_point *pb, t_screen *fst, t_line *nw)
{
	nw->x0 = fl_to_int(pa->x);
	nw->x1 = fl_to_int(pb->x);
	nw->y0 = fl_to_int(pa->y);
	nw->y1 = fl_to_int(pb->y);
}

static t_line	*ft_newline(t_point *pa, t_point *pb, t_line *nw, t_screen *fst)
{
	if (!(nw = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	ft_setpoint(pa, pb, fst, nw);
	nw->dx = nw->x1 - nw->x0;
	nw->dy = nw->y1 - nw->y0;
	if (nw->dy < 0)
	{
		nw->dy = (nw->dy) * -1;
		nw->stepy = -1;
	}
	else
		nw->stepy = 1;
	if (nw->dx < 0)
	{
		nw->dx = -(nw->dx);
		nw->stepx = -1;
	}
	else
		nw->stepx = 1;
	nw->x = nw->x0;
	nw->y = nw->y0;
	return (nw);
}

static int		ft_steps_else(t_line *line)
{
	line->p = (2 * line->dx) - line->dy;
	line->ince = 2 * line->dx;
	line->incne = 2 * (line->dx - line->dy);
	return (0);
}

static int		ft_steps(t_line *line, t_screen *fst, unsigned int col)
{
	if (line->dx > line->dy)
	{
		line->p = (2 * line->dy) - line->dx;
		line->ince = 2 * line->dy;
		line->incne = 2 * (line->dy - line->dx);
		while (line->x != line->x1)
		{
			line->x += line->stepx;
			if (line->p < 0)
				line->p += line->ince;
			else
			{
				line->y += line->stepy;
				line->p += line->incne;
			}
			if (line->x > 0 && line->x < fst->len && line->y > 0)
				((unsigned int *)fst->data)[line->x + line->y * fst->len] = col;
		}
		return (1);
	}
	else
		return (ft_steps_else(line));
}
