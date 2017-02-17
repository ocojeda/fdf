/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:58:06 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/17 17:06:13 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_line	*ft_newline(t_point *pointA, t_point *pointB)
{
	t_line		*new;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	new->x0 = pointA->x;
	new->y0 = pointA->y;
	new->x1 = pointB->x;
	new->y1 = pointB->y;
	new->dx = new->x1 - new->x0;
	new->dy = new->y1 - new->y0;
	if (new->dy < 0)
	{
		new->dy = (new->dy) * -1;
		new->stepy = -1;
	}
	else
		new->stepy = 1;
	if (new->dx < 0)
	{
		new->dx = -(new->dx);
		new->stepx = -1;
	}
	else
		new->stepx = 1;
	new->x = new->x0;
	new->y = new->y0;
	return (new);
}

static int		ft_steps(t_line *line, t_screen *fst, unsigned int color)
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
			if (((line->x + line->y * fst->length) > 0) && ((line->x + line->y * fst->length) < (fst->length * fst->hight)))
				((unsigned int *)fst->data)[line->x + line->y*fst->length] = color;
		}
		return (1);
	}
	else
	{
		line->p = (2 * line->dx) - line->dy;
		line->ince = 2 * line->dx;
		line->incne = 2 * (line->dx - line->dy);
		return (0);
	}
}

t_point		*new_point(float x, float y, float z, unsigned int color)
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
void		ft_put_diagonal(t_point *pointA, t_point *pointB, t_screen *fst)
{
	t_line		*line;
	
	if (pointA && pointB)
	{
 		line = ft_newline(pointB, pointA);
		if (!ft_steps(line, fst, pointB->color))
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
				if (((line->x + line->y * fst->length) > 0) && ((line->x + line->y * fst->length) < (fst->length * fst->hight)))
					((unsigned int *)fst->data)[line->x + line->y * fst->length] = pointB->color;
			}
		}
		free(line);
	}
}
