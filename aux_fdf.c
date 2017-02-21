/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:40:30 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/21 11:21:54 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"fdf.h"

t_point		*ft_mapcpy(t_point *fp)
{
	t_point		*temp;
	t_point		*temp2;
	t_point 	*temp3;
	t_point		*temp4;
	t_point 	*temp5;

	temp = fp;
	temp2 = fp;		
	temp3 = ft_newpoint(temp2->x, temp2->y, temp2->z, temp2->color);
	temp4 = temp3;
	temp5 = temp4;
	while (temp)
	{
		temp2 = temp;
		while (temp2)
		{
			if(temp2->nextx)
			temp3->nextx = ft_newpoint(temp2->nextx->x, temp2->nextx->x, temp2->nextx->z, temp2->nextx->color);
			if(temp2->nexty)
			temp3->nexty = ft_newpoint(temp2->nexty->x, temp2->nexty->y, temp2->nexty->z, temp2->nexty->color);
			temp2 = temp2->nextx;
			temp3 = temp3->nextx;
		}
		temp3 = temp4->nexty;
		temp4 = temp4->nexty;
		temp= temp->nexty;
	}
	return (fp);
}
