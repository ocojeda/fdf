/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:58:06 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/20 11:41:52 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_setpoint(t_point *pa, t_point *pb, t_screen *fst, t_line *nw)
{
	if (pa->x < 0)
		nw->x0 = 0;
	else if (pa->x > fst->len)
		nw->x0 = fst->len;
	else
		nw->x0 = pa->x;
	if (pb->x < 0)
		nw->x1 = 0;
	else if (pb->x > fst->len)
		nw->x1 = fst->len;
	else
		nw->x1 = pb->x;
	if (pa->y < 0)
		nw->y0 = 0;
	else if (pa->y > fst->hight)
		nw->y0 = fst->hight;
	else
		nw->y0 = pa->y;
	if (pb->y < 0)
		nw->y1 = 0;
	else if (pv->y > fst->hight)
		nw->y1 = fst->hight;
	else
		nw->y1 = pb->y;
}

static t_line	*ft_newline(t_point *pa, t_point *pb, t_line *nw, t_screen *fst)
{
	if (!(nw = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	ft_setpoint(pa, pb, fst, new);
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
			if (((line->x + line->y * fst->len) > 0) && ((line->x + line->y\
					* fst->len) < (fst->len * fst->hight)))
				((unsigned int *)fst->data)[line->x + line->y * fst->len] = col;
		}
		return (1);
	}
	else
		return (ft_steps_else(line));
}

t_point			*new_point(float x, float y, float z, unsigned int color)
{
	t_point		*new;

	if (!(new = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = color;
	new->nextx = NULL;
	new->nexty = NULL;
	return (new);
}

int				ft_boundaries(t_point *pa, t_point *pb, int len, int hight)
{
	if (pa->x < 0 && pb->x < 0)
		return (0);
	if (pa->y < 0 && pb->y < 0)
		return (0);
	if (pa->x > len && pb->x > len)
		return (0);
	if (pa->y > hight && pb->y > hight)
		return (0);
	return (1);
}

void			ft_put_diagonal(t_point *pointa, t_point *pointb, t_screen *fst)
{
	t_line		*line;

	if (pointa && pointb && ft_boundaries(pointa, pointb, fst->len, fst->hight))
	{
		line = ft_newline(pointb, pointa, NULL, fst);
		if (!ft_steps(line, fst, pointb->color))
		{
			while (line->y != line->y1)
			{
				line->y += line->stepy;
				if (line->p < 0)
					line->p += line->ince;
				else
				{
					line->x += line->stepx;
					line->p += line->incne;
				}
				((unsigned int *)fst->data)[line->x + line->y * \
					fst->len] = pointb->color;
			}
		}
		free(line);
	}
}
