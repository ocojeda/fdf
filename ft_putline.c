/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:58:06 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/09 19:14:53 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_order_points(t_point *pointA, t_point *pointB)
{
	int temp;
	if(pointB->y < pointA->y || (pointA->x > pointB->x && pointA->y == pointB->y))
	{
		temp = pointB->x;
		pointB->x = pointA->x;
		pointA->x = temp;
		temp = pointB->y;
		pointB->y = pointA->y;
		pointA->y = temp;
	}
}
t_line	*ft_newline(t_point *pointA, t_point *pointB)
{
	t_line *new;
	if(!(new = (t_line *)malloc(sizeof(t_line))))
		return NULL;
	new->x = pointA->x;
	new->y = pointA->y;
	new->dx = pointB->x - pointA->x;
	new->dy = pointB->y - pointA->y;
	if(new->dy < 0)
	{
		new->dy = (new->dy) * -1;
		new->stepy = -1;
	}
	else
		new->stepy = 1;
	if(new->dx < 0)
	{
		new->dx = -(new->dx);
		new->stepx = -1;
	}
	else
		new->stepx = 1;
	return new;
}

int	ft_steps(t_line *line, t_screen *fst, t_point *pointB)
{
	if(line->dx > line->dy)
	{
		line->p = (2 * line->dy) - line->dx;
		line->ince = 2 * line->dy;
		line->incne = 2 * (line->dy - line->dx);
		while(line->x < pointB->x)
		{
			line->x += line->stepx;
			if(line->p < 0)
				line->p += line->ince;
			else
			{
				line->y += line->stepy;
				line->p += line->incne;
			}
			((unsigned int *)fst->data)[line->x + line->y*fst->length] = pointB->color;
		}
		return 1;
	}
	else
	{
		line->p = (2 * line->dx) - line->dy;
		line->ince = 2 * line->dx;
		line->incne = 2 * (line->dx - line->dy);
		return 0;
	}
}
t_point		*new_point(int x, int y, int z, unsigned int color)
{
	t_point *new;
	if(!(new = (t_point *)malloc(sizeof(t_point))))
		return NULL;
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = color;
	new->nextx = NULL;
	new->nexty = NULL;
	return new;
}
void ft_put_pix_diagonal(t_point *pointA, t_point *pointB, t_screen *fst)
{
	t_line *line;

	line = ft_newline(pointA, pointB);
	if(!ft_steps(line, fst, pointB))
	{
		while(line->y < pointB->y)
		{
			line->y += line->stepy;
			if(line->p < 0)
				line->p += line->ince;
			else
			{
				line->x += line->stepx;
				line->p += line->incne;
			}
			((unsigned int *)fst->data)[line->x + line->y * fst->length] = pointB->color;
		}
	}
	free(line);
}
