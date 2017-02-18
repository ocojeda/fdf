/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:58:06 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/18 19:33:00 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_setpoint(t_point *pointa, t_point *pointb, t_screen *fst, t_line *new)
{
	if(pointa->x < 0)
		new->x0 = 0;
	else if(pointa->x > fst->len)
		new->x0 = fst->len;
	else
		new->x0 = pointa->x;
	if(pointb->x < 0)
		new->x1 = 0;
	else if(pointb->x > fst->len)
		new->x1 = fst->len;
	else
		new->x1 = pointb->x;
	if(pointa->y < 0)
		new->y0 = 0;
	else if(pointa->y > fst->hight)
		new->y0 = fst->hight;
	else
		new->y0 = pointa->y;
	if(pointb->y < 0)
		new->y1 = 0;
	else if(pointb->y > fst->hight)
		new->y1 = fst->hight;
	else
		new->y1 = pointb->y;
}
static t_line	*ft_newline(t_point *pointa, t_point *pointb, t_line *new, t_screen*fst)
{
	
	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	ft_setpoint(pointa, pointb, fst, new);
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
int				ft_boundaries(t_point *pointa, t_point *pointb, int len, int hight)
{
	if(pointa->x < 0 && pointb->x < 0)
		return 0;
	if(pointa->y < 0 && pointb->y < 0)
		return 0;
	if(pointa->x > len && pointb->x > len)
		return 0;
	if(pointa->y > hight && pointb->y > hight)
		return 0;
	return 1;
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
