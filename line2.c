/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 14:23:55 by tfaure            #+#    #+#             */
/*   Updated: 2017/02/26 16:36:12 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	if (ft_boundaries(pointa, pointb, fst->len, fst->hight))
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
				if (line->x < fst->len && line->x > 0)
					((unsigned int *)fst->data)[line->x + line->y * \
						fst->len] = pointb->color;
			}
		}
		free(line);
	}
}
